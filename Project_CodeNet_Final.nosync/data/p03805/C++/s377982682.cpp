#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <iomanip>
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef pair<int,int> P;
//小数点以下　cout << fixed << setprecision(10) << num << endl;
//桁数はlog10(mid)でやれ　log(mid)/log(10)はWA
const int INF = 100100100;
int main(){
    int n,m; cin >> n >> m;
    vector<int> v;
    for(int i=1;i<n;i++) v.push_back(i);
    vector<vector<int>> to(n);
    rep(i,m){
        int a,b; cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    int ans=0;
    do{
        int res=0;
        rep(i,n-1){
            for(auto u:to[v[i]]){
                if(i==0 && u==0) res++;
                else if(u==v[i-1]) res++;
            }
        }
        if(res==n-1) ans++;
    }while(next_permutation(v.begin(),v.end()));
    cout << ans;
}
