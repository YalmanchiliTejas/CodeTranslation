#include <bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<(int)(n);i++)
#define FORR(i,m,n) for(int i=(int)(m);i<(int)(n);i++)
#define pb(a) push_back(a)
#define mp(x,y) make_pair(x,y)
#define ZERO(a) memset(a,0,sizeof(a))
#define len(a) sizeof(a)
#define ll long long
#define pii pair<int,int>
#define INF 1<<29
#define MAX 101010
using namespace std;

int a[MAX],p[MAX/2];

void solve(){
 int n;
 for(;;){
  cin>>n;
  if(!n) break;
  int ans=0;
  FOR(i,n) cin>>a[i];
  for(int i=0;2*i+1<n;i++){
   if(a[2*i]==a[2*i+1]){
    p[i]=a[2*i];
    continue;
   }
   p[i]=a[2*i+1];
   int t=i-1;
   while(t>=0&&p[t]!=p[i]) p[t--]=p[i];
  }
  for(int i=0;2*i+1<n;i++){
   ans+=(p[i]^1)<<1;
  }
  if(n&1&&a[n-1]==0) ans++;
  cout<<ans<<endl;
 }
}

int main(){
 solve();
 return 0;
}