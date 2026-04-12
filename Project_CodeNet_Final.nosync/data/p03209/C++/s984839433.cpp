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
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;
    using namespace std;

ll n,x;
ll res[100];
ll sum[100];

ll func(int m,ll y){
  if(y==sum[m])return res[m];
  else if(m>=y && m>=1) return 0;
  else if(m>=1 && y==res[m]) return res[m-1]+1;
  else if(m>=1 && y<res[m]) return func(m-1,y-1);
  else if(m>=1 && y>res[m]) return res[m]-func(m,sum[m]-y);
  else{
    return 1;
  }
}

    int main(){
      cin >> n >> x;
      rep(i,n+1){
       res[i]=pow(2,i+1)-1;
        sum[i]=pow(2,i+2)-3;
      }
      cout << func(n,x) << endl;
      return 0;}