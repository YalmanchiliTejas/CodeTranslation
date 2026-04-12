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
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

bool a[200],b[200];
int main(){
    int n,m;
    cin>>n>>m;
    string s[n];
    rep(i,n){
        cin>>s[i];
        rep(j,m){
            a[i]=a[i]||(s[i][j]=='#');
            b[j]=b[j]||(s[i][j]=='#');
        }
    }
    rep(i,n){
        rep(j,m){
        if(a[i]&&b[j])cout<<s[i][j];
        }
        if(a[i])cout<<endl;
    }
    return 0;
}
