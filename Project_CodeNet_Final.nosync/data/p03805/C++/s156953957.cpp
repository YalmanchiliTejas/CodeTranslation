#include <bits/stdc++.h> 
#define rep(i,n) for(int i=0; i<(n); ++i)
#define cout(x) cout<<x<<endl
#define all(v) v.begin(), v.end()
using namespace std;
//型エイリアス
using vi = vector<int>;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
const ll inf = 1e18;
const int N = 2e5 + 10;


int main(){
    int n,m;
    cin >> n >> m;
    vi a(m),b(m);
    rep(i,m) cin >> a[i] >> b[i];

    vi path(n);
    rep(i,n) path[i] = i+1;
    int ans = 0;
    do{
        bool can = false;
        rep(i,n-1){
            can = false;
            rep(j,m){
                if((path[i]==a[j]&&path[i+1]==b[j]) || (path[i+1]==a[j]&&path[i]==b[j])){
                    can = true;
                    break;
                }
            }
            if(can==false) break;
        }
        if(can && path[0]==1) ans += 1; 
    }
    while(next_permutation(all(path)));

    cout(ans);
    return 0;
}