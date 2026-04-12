#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = n-1; i >= 0; i--)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define sz(x) ((int)(x).size())
typedef long long ll;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VP = vector<P>;
template<typename T> void view(T e){std::cout << e << std::endl;}
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

const int inf = 1 << 30;
const ll INF = 1LL << 60;

int main(){
    int n;
    string s;
    cin >> n >> s;
    vector<string> tl = {"SS", "SW", "WS", "WW"};
    rep(i,4){
        string t = tl[i];
        for(int i = 1; i < n-1; i++){
            if ((t[i] == 'W' && s[i] == 'o') || (t[i] == 'S' && s[i] == 'x')){
                if (t[i-1] == 'S') t += 'W';
                else t += 'S';
            }else{
                if (t[i-1] == 'S') t += 'S';
                else t += 'W';
            }
        }
        t = t[sz(t)-1] + t + t[0];
        bool ok = true;
        for(int i = 1; i <= n; i++){
            if ((t[i] == 'W' && s[i-1] == 'o') || (t[i] == 'S' && s[i-1] == 'x')){
                if (t[i-1] == t[i+1]) ok = false;
            }else{
                if (t[i-1] != t[i+1]) ok = false;
            }
        }
        if (!ok) continue;
        t = t.substr(1, n);
        view(t);
        return 0;
    }
    view(-1);
    return 0;
}