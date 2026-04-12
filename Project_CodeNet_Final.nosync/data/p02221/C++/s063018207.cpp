#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
constexpr int inf=1e9+7;
constexpr ll longinf=1LL<<60 ;
constexpr ll mod=1e9+7 ;


int a[1<<20][20];
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int m = 1<<n;
    string s;
    cin>>s;
    rep(i,m){
        cin>>a[i][0];
        a[i+m][0]=a[i+2*m][0]=a[i+3*m][0]=a[i][0];
    }
    rep(j,n){
        rep(i,2*m){
            if(a[i+(1<<j)][j]==0)continue;
            if(s[abs(a[i][j]-a[i+(1<<j)][j])-1]=='1'){
                a[i][j+1]=max(a[i][j],a[i+(1<<j)][j]);
            }
            else {
                a[i][j+1]=min(a[i][j],a[i+(1<<j)][j]);
            }
        }
    }

    rep(i,m){
        cout<<a[i][n]<<"\n";
    }
    return 0;
}
