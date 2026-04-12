
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
  int n,a,b;
  pii p[100];
  rep(i,INF){  
    scanf("%d,%d",&a,&b);
    if(a==0 && b==0)break;
    p[i].first=b;
    p[i].second=a;
  }
  int m=i;
  sort(p,p+m);
  vi ans(105);
  ans[p[m-1].second]=1;
  for(i=m-2;i>=0;i--){
    if(p[i].first==p[i+1].first)ans[p[i].second]=ans[p[i+1].second];
    else ans[p[i].second]=ans[p[i+1].second]+1;
  }
  while(cin>>n) cout<<ans[n]<<endl;
}