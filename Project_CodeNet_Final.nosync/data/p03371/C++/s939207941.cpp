#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MOD = 1000000007;
const int INF = 999999999;

int main(){
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int m = min(X, Y);
    int money = 0;
    money += min(m*(A+B),2*m*C);
    X -= m;
    Y -= m;
    if(X < Y){
        money += min(Y*B, 2*Y*C);
    }else{
        money += min(X*A, 2*X*C);
    }
    cout << money << endl;
return 0;}
/**
 * g++ code.cpp
 * ./a.out
 * shift + ctrl + i
**/ 