#include<bits/stdc++.h>
 using namespace std;
 using Graph = vector<vector<int>>;
 #define rep(i,n) for(int i=0;i<n;++i)
 #define all(v) v.begin(), v.end()
 typedef long long int ll;
 typedef unsigned long long ull;
 template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
 template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
 typedef pair<ll,ll> P;
 const long long MOD = 1e9+7;
 const ll INF = 1LL << 60;


 int main(){
    bool G[10][10] ={false};

    int n,m;
    cin >> n >> m;
    rep(i, m){
        int a,b;
        cin >> a >> b; --a, --b;
        G[a][b] = G[b][a] = true;
    }

    //順列
    vector<int> ord(n);
    for(int i = 0; i < n; i++){
        ord[i] = i;
    }

    //順列を全部試す
    int res = 0;

    do{
        if(ord[0] != 0)break;

        bool ok = true;

        for(int i = 0; i < n - 1; i++){
            int from = ord[i];
            int to = ord[i+1];

            if(!G[from][to]){//パスがないとき
                ok = false;
            }
        }
        if(ok)res++;
    }while(next_permutation(all(ord)));

    cout << res << endl;


 }
