#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(int)(a); (i)<(int)(b); ++(i))
#define rFor(i, a, b) for(int (i)=(int)(a)-1; (i)>=(int)(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef unsigned long long ulint;
typedef pair<int, int> pii;
typedef pair<lint, lint> pll;
template<class T> bool chmax(T &a, const T &b){if(a<b){a=b; return true;} return false;}
template<class T> bool chmin(T &a, const T &b){if(a>b){a=b; return true;} return false;}
template<class T> T div_floor(T a, T b){
    if(b < 0) a *= -1, b *= -1;
    return a>=0 ? a/b : (a+1)/b-1;
}
template<class T> T div_ceil(T a, T b){
    if(b < 0) a *= -1, b *= -1;
    return a>0 ? (a-1)/b+1 : a/b;
}

constexpr lint mod = 1e9+7;
constexpr lint INF = mod * mod;
constexpr int MAX = 500010;

int main(){
    char trump;
    string s[4][13];
    string str = "23456789TJQKA";
    auto mx = [&](string a, string b, char suit){
        if(a[1] == trump && b[1] != trump) return a;
        else if(a[1] != trump && b[1] == trump) return b;
        else if(a[1] == trump && b[1] == trump) return str.find(a[0]) > str.find(b[0]) ? a : b;
        else{
            if(a[1] == suit && b[1] != suit) return a;
            else if(a[1] != suit && b[1] == suit) return b;
            else return str.find(a[0]) > str.find(b[0]) ? a : b;
        }
    };
    while(cin >> trump && trump != '#'){
        rep(i, 4)rep(j, 13) cin >> s[i][j];
        int leader = 3, ew = 0, ns = 0;
        rep(i, 13){
            char suit = s[leader][i][1];
            pair<string, int> p = {s[leader][i], leader};
            rep(j, 4)if(mx(p.fi, s[j][i], suit) != p.fi){
                p = {s[j][i], j};
            }
            p.se == 0 || p.se == 2 ? ++ns : ++ew;
            leader = p.se;
        }
        printf("%s ", ns > ew ? "NS" : "EW");
        printf("%d\n", max(ns, ew) - 6);
    }
}
