#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int check(int a,int b);

int main(){
    int A,B,C,X,Y;
    cin >> A >> B >> C >>X >> Y ;
    long long ans = X * A + Y * B ;
    for(int i = 0;  i <= 2 * max(X,Y); i+=2){
        long long p = C * i + A * check(X,i) + B * check(Y,i);
        if(p < ans) ans = p ;
    }
    cout << ans << endl ;


}

int check(int a, int b){
    if((a - b / 2) < 0) return 0;
    else return (a - b / 2) ;
}