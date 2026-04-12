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
constexpr int MAX = 100010;

using B = vector<string>;

B hoge(string &s){
    int cnt = 0;
    for(char c: s) cnt += (c == '/');
    B ret(cnt+1);
    int i = 0;
    for(char c: s){
        if(c == '/'){
            ++i;
            continue;
        }
        if(c == 'b') ret[i] += "b";
        else{
            rep(_, c-'0') ret[i] += ".";
        }
    }
    return ret;
}

string fuga(B &a){
    string s;
    rep(i, a.size()){
        int l = 0;
        while(l < a[i].size()){
            if(a[i][l] == 'b'){
                s += "b";
                ++l;
                continue;
            }
            int r = l;
            while(r < a[i].size() && a[i][l] == a[i][r]) ++r;
            s += '0' + (r-l);
            l = r;
        }
        if(i < a.size()-1) s += "/";
    }
    return s;
}

int main(){
    string s;
    while(cin >> s && s != "#"){
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        auto tmp = hoge(s);
        tmp[a-1][b-1] = '.';
        tmp[c-1][d-1] = 'b';
        cout << fuga(tmp) << "\n";
    }
}
