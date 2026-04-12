#include <bits/stdc++.h>
using namespace std;
#define  rep(i, n) for(int i = 0; i < n; i++) 
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  INF 1LL << 60
typedef long long int LL;
typedef long long int ll;
#define pll pair<ll, ll>
#define F first
#define S second
const int MOD = 1000000007;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }
//sort(all(x))とするとソートできるよ
// 10^x は pow(10,(x)) 
// 任意のlogは　対数の底の変換を使う    log(N) / log(任意の底)

int main(){
    int N;cin >> N;
    vector<string> s(N);rep(i,N)cin >> s[i];
    vector<map<char,int>> vm(N);

    rep(i,N){
        if(i == 0){
            rep(j,s[i].size())vm[i][s[i][j]]++;
        }
        else{
            rep(j,s[i].size()){
                if(vm[0][s[i][j]] > vm[i][s[i][j]])vm[i][s[i][j]]++;
            }
        }
    }

    map<char,int> m2;
    rep(i,N){
        for(auto t : vm[i]){
            int tmp = t.S;
            char a = t.F;
            rep(k,N){
                chmin(tmp,vm[k][a]);
            }
            m2[a] = tmp;
        }
    }

    for(auto t : m2){
        cout << string(t.S,t.F); 
    }
    cout << endl;
}
