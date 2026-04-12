#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using ll = long long;
using P = pair<int,int>;
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}




int main()
{
    ll A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;

    ll PA = 0;
    ll PB = 0;
    ll PC = 0;

    //A A、Bのみ
    PA = A * X + B * Y;

    //B Cのみ
    ll Z = max(X,Y);
    PB = C * 2 * Z;

    //C　組み合わせ
    ll ZZ = min(X,Y);
    if(X > Y) PC = C * 2 * ZZ + A * (X - Y);
    else PC = C * 2 * ZZ + B * (Y - X);

    ll P = 0;
    P = min(PA,min(PB,PC));
    cout << P << endl;

    return 0;
}
//Ctrl+Shift+Bでコンパイルと実行を行ってデバッグすること