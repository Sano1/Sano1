/*
http://informatics.mccme.ru/moodle/mod/statements/view3.php?id=762&chapterid=1002#1
Задача решена методом динамического программирования.
На каждом шаге цикла для i-го человека ищется минимальная стоимость билетов купленных перед ним "min_".
d3,d2 и d1 минимальные стоимости билетов "дошедшие" до троих стоящих перед ним людей.
Минимальная стоимость выбирается из 3-ёх вариантов -
сам себе купил билет или ему купил билет i-1 или i-2 человек очереди.
*/

#include <fstream>
#include <math.h>

using namespace std;
int main(void)
{
    int n,i,a[5005],b[5005],c[5005],d1,d2,d3,min_;
    ifstream in;
    ofstream out;
    in.open("input.txt");
    out.open("output.txt");
    in>>n;
    a[1]=20000; b[1]=20000; c[1]=20000;
    a[2]=20000; b[2]=20000; c[2]=20000;
    a[n+1]=20000; b[n+1]=20000; c[n+1]=20000;
    a[n+2]=20000; b[n+2]=20000; c[n+2]=20000;
    d1=0;d2=0;d3=0;
    for (i=3;i<=n+2;i++) 
    {
        in>>a[i]>>b[i]>>c[i];
        min_=min(min(c[i-2]+d1,b[i-1]+d2),a[i]+d3);
        d1=d2;
        d2=d3;
        d3=min_;  
    }
    out<<d3<<endl;
    
    in.close();
    out.close();
    return 0;    
}
