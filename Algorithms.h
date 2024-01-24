#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#endif // ALGORITHMS_H

#define INF 9999

#include <cmath>
#include <QPainter>
#include <string>

using namespace std;

struct ver {
    double minval;
    string path;
    bool used;
};

void testing(){

}

// соединение узлов рёбрами
void LineFromCToC(int x1, int y1, int x2, int y2, QPainter *painter){
    float min = INF,
        xm1, ym1,  // лучшие значения
        xm2, ym2,
        xb, yb,  // очередная найденная точка окружности
        grad = 0,  // угол в градусах
        rad = 0;  // угол в радианах
    x1 += 12;  // из данных координат получаются центры окружностей
    x2 += 12;
    y1 += 12;
    y2 += 12;
    xm1 = cos(rad) * 12 + x1;
    ym1 = sin(rad) * 12 + y1;
    xb = cos(rad) * 12 + x1;
    yb = sin(rad) * 12 + y1;
    while(grad < 360){  // перебор точек второй окружности
        if (min > sqrt(pow(x2 - xb , 2) + pow(y2 - yb , 2)) ){  // проверка точки на минимум
            min = sqrt(pow(x2 - xb , 2) + pow(y2 - yb , 2));  // запись нового минимума
            xm1 = xb;
            ym1 = yb;
        }
        grad ++;// переход к следующей итерации
        rad = grad * M_PI / 180.0;

        xb = cos(rad) * 12 + x1;
        yb = sin(rad) * 12 + y1;
    }
    min = INF;
    grad = 0,
        rad = 0;
    xm2 = cos(rad) * 12 + x2;
    ym2 = sin(rad) * 12 + y2;
    xb = cos(rad) * 12 + x2;
    yb = sin(rad) * 12 + y2;
    while(grad < 360){  // перебор точек второй окружности
        if (min > sqrt(pow(x1 - xb , 2) + pow(y1 - yb , 2)) ){  // проверка точки на минимум
            min = sqrt(pow(x1 - xb , 2) + pow(y1 - yb , 2));  // запись нового минимума
            xm2 = xb;
            ym2= yb;
        }
        grad ++;  // переход к следующей итерации
        rad = grad * M_PI / 180.0;

        xb = cos(rad) * 12 + x2;
        yb = sin(rad) * 12 + y2;
    }
    //  рисование ребра по полученным ближайшим друг к другу точкам
    painter->drawLine((int)xm1, (int)ym1, (int)xm2, (int)ym2);
}

// реализация алгоритма Дейкстры
vector<ver> Dijcstra(int a, double v[10][10]){
    vector<ver> arr(10);
    int n = 10, ve;
    a--;
    for (int i = 0; i < 10; i++){
        arr[i].minval = INF;
        arr[i].path = "";
        arr[i].used = false;
    }
    arr[a].minval = 0;
    arr[a].path = to_string(a + 1);
    for (int i = 0; i < n; i++){
        ve = -1;
        for (int j = 0; j < n; j++){
            if (!arr[j].used && (ve == -1 || arr[ve].minval > arr[j].minval )){
                ve = j;
            }
        }
        if (arr[ve].minval == INF){
            break;
        }
        arr[ve].used = true;
        for(int j = 0; j < n; j++){
            if(arr[ve].minval + v[ve][j] < arr[j].minval){
                arr[j].minval = arr[ve].minval + v[ve][j];
                arr[j].path = arr[ve].path + "-" + to_string(j + 1);
            }
        }
    }

    return arr;
}
