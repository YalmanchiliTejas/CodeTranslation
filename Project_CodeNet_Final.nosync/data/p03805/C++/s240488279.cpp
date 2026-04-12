#define _GLIBCXX_DEBUG
#include <bits/stdc++.h> //C++の機能を「全て」読み込むための命令
#define rep(i,n) for(int i=0; i<(n); ++i)
#define cout(x) cout<<x<<endl
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using Mat = vector<vector<int>>;

int main(){
    int n, m;
    cin >> n >> m;
    vi a(m),b(m);
    rep(i, m) cin >> a[i] >> b[i];

    vi node(n);
    for(int i=1; i<=n; ++i) node[i-1] = i;
    int ans = 0;

    do{
        bool can = false;
        rep(i,n-1){
            can = false;
            rep(j,m){
                if((node[i]==a[j] && node[i+1]==b[j]) || (node[i]==b[j] && node[i+1]==a[j])){
                    can = true;
                    break;
                }
            }
            if(can==false) break;
        }
        if(can && node[0]==1) ans += 1; 
    }
    while(next_permutation(all(node)));

    cout(ans);
    
    return 0;
}