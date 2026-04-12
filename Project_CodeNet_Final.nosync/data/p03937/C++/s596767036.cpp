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
#include <map>
#include <cstring> //memset(dp,0,sizeof(dp))
#include <functional>
#include <cctype>
#include <locale>
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define fi first
#define se second
#define pb push_back
#define ALL(a) (a).begin(),(a).end()
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef pair<int,int> P;
typedef pair<long long,long long> Pll;
#define fout(num) cout << fixed << setprecision(20) << (num) << endl
//s[i]=tolower(s[i]); islower(s[i]); cout << tolower(s[i])はバグ
//vector<vector<ll>> dp(n,vector<ll>(n))


signed main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int h,w; cin >> h >> w;
    char a[h][w];
    int cnt=0;
    rep(i,h)rep(j,w){
        cin >>  a[i][j];
        if(a[i][j]=='#') cnt++;
    }
    if(cnt!=h+w-1||a[0][0]!='#'||a[h-1][w-1]!='#'){
        cout << "Impossible" << endl;
        return 0;
    }
    int s=0,t=0;
    while((s!=h-1)&&(t!=w-1)){
        if(a[s+1][t]=='#') s++;
        else if(a[s][t+1]=='#') t++;
        else{
            cout << "Impossible" << endl;
            return 0;
        }
    }
    cout << "Possible" << endl;
}
