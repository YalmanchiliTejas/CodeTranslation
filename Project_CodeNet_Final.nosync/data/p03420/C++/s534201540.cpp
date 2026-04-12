
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<math.h>
#include<string>
#include<string.h>
#include<stack>
#include<queue>
#include<vector>
#include<utility>
#include<set>
#include<map>
#include<stdlib.h>
#include<iomanip>

using namespace std;

#define ll long long
#define ld long double
#define EPS 0.0000000001
#define INF 1e9
#define MOD 1000000007
#define rep(i,n) for(i=0;i<(n);i++)
#define loop(i,a,n) for(i=a;i<(n);i++)
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)

typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;

int main(void) {
  int i,j;
  ll n,k;
  cin>>n>>k;
  if(k==0){
    cout<<n*n<<endl;
    return 0;
  }
  ll ans=0;
  int b;
  loop(b,k+1,n+1){
    if(n%b<k){
      ans+=(b-k)*(n/b);
    }else{
      int t=max(k,n%b);
      ans+=(t-k+1)*(n/b+1)+(b-t-1)*(n/b);
    }
    //cout<<ans<<endl;
  }
  cout<<ans<<endl;
}
