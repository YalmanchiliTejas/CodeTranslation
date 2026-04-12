#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1001001001LL;
constexpr long long LINF = 1e18 + 10;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }



int main(){
    int n; cin >> n;
    string s; cin >> s;

    vector<char> res;
    rep(num, 4){
        vector<char> a(n);
        a[0] = (num&1) ? 'S' : 'W';
        a[1] = (num&(1<<1)) ? 'S' : 'W';
        rept(i, 1, n-1){
            char nx;
            if(a[i] == 'S' && s[i]== 'o' || a[i] == 'W' && s[i] == 'x') nx = a[i-1];
            else nx = a[i-1] == 'S' ? 'W' : 'S';
            a[i+1] = nx;
        }
        //判定
        if(a[n-1] == 'S'){
            if(s[n-1] == 'o' && a[n-2] != a[0])continue;
            if(s[n-1] == 'x' && a[n-2] == a[0])continue;
        }else{
            if(s[n-1] == 'o' && a[n-2] == a[0])continue;
            if(s[n-1] == 'x' && a[n-2] != a[0])continue;            
        }
        if(a[0] == 'S'){
            if(s[0] == 'o' && a[n-1] != a[1])continue;
            if(s[0] == 'x' && a[n-1] == a[1])continue;
        }else{
            if(s[0] == 'o' && a[n-1] == a[1])continue;
            if(s[0] == 'x' && a[n-1] != a[1])continue;            
        }
        res = a;
        break;
    }

    if(res.size()){
        for(char c: res) cout << c; cout << ln;
    }else cout << -1 << ln;
}