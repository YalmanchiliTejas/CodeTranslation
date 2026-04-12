#include <iostream>

typedef long long ll;

#define FOR(i,a,b) for(ll i = (a);i < (b);++i)
#define REP(i,n) FOR(i,0,n)

#define debug(x) cout << #x << "=" << x << endl;

using namespace std;

//A.Restaurant

//８００円のランチ
//１５食ごとに２００円のキャッシュバック
//食べた数 N が与えられる

//払った金額 x ともらった金額 y の差 x-y を求める

int calcReCush(int N){

    int eatNum = 15;
    int reCush = 200;
    
    return (N / eatNum) * reCush;
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
