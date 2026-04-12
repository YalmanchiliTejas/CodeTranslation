#include<iostream>

using namespace std;

//８００円のランチ
//１５食ごとに２００円のキャッシュバック
//食べた数 N が与えられる
//払った金額 x ともらった金額 y の差 x-y を求める

int calcReCush(int N){

    int hoge = 15;
    int reCush = 200;
    
    return (N / hoge) * reCush;
}

int main(void){

    int N;
    cin >> N;

    int LunchPrice = 800;
    int x = LunchPrice * N;
    int y = calcReCush(N);

    cout << x - y << endl;
    
    return 0;
}
