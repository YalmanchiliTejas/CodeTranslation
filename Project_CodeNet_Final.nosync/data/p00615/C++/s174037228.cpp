
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
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
#define rep(i,n) for(i=0;i<n;i++)
#define loop(i,a,n) for(i=a;i<n;i++)
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)

typedef vector<int> vi;
typedef pair<int,int> pii;

int main(void) {
  int i,j;
  int n,m;
  while(1){
    cin>>n>>m;
    if(n+m==0)break;
    vi a(n+m+1);
    a[0]=0;
    rep(i,n)cin>>a[i+1];
    rep(i,m)cin>>a[n+i+1];
    sort(all(a));
    int ans=0;
    rep(i,n+m)ans=max(ans,a[i+1]-a[i]);
    cout<<ans<<endl;
  }
}