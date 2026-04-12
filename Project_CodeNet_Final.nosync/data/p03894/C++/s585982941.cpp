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
  int n,q;
  cin>>n>>q;
  vi c(n,0);
  c[0]=1;
  c[1]=-1;
  int ball=0;
  rep(i,q){
    int a,b;
    cin>>a>>b;
    a--;b--;
    swap(c[a],c[b]);
    if(a==ball)ball=b;
    else if(b==ball)ball=a;
    if(ball>0 && c[ball-1]==0)c[ball-1]=-1;
    if(ball<n-1 && c[ball+1]==0)c[ball+1]=-1;
  }
  int ans=0;
  rep(i,n)if(c[i]!=0)ans++;
  cout<<ans<<endl;
}
