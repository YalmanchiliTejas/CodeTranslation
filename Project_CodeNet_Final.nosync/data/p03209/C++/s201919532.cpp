#include<iostream>
using namespace std;
typedef long long ll;
long long a[51], p[51];
ll f(ll n, ll x);
int main() {
    ll n, x;
    cin >> n >> x;
    a[0] = p[0] = 1; //レベル0バーガー Pのみ
    for (int i = 1; i <= n; i++) {
        a[i] = 1 + a[i - 1] + 1 + a[i - 1] + 1;
        p[i] = p[i - 1] + 1 + p[i - 1];
    }
    cout << f(n, x) << endl;
}
ll f(ll n, ll x) {
    if (n == 0) { //レベル0バーガー
        if (x <= 0) { //下から0層 ないでしょ
            /* <= を == にしたら input 2 7 で事故った
             2 7
             else return p[1] + 1 + f(1, 7 - (1 + a[1] + 1) = 3 + 1 + f(1, 0)
             1 0
             レベル1バーガーの下から0層？ 0
             a[-1]?
             */
            return 0;
        } else {
            return 1;
        }
    } else if (x <= 1 + a[n - 1]) { // B + (前のバーガー)
        return f(n - 1, x - 1); //一番下のBを除いた
    } else { //上の P + (前のバーガー) + B
        return p[n - 1] + 1 + f(n - 1, x - (1 + a[n - 1] + 1));
        //下の B + (前のバーガー) + P を除く 一番上のBはどうでもいい
        //1層下のバーガーで下から、上のバーガーで除いた B + () + P を除いた残りの個数をみる
    }
}
