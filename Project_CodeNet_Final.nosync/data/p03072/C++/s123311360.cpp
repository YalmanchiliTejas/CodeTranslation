#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
#include<utility>//pair
#include<cmath>//abs,sqrt
#include<cstring>
#include<map>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define prin(arg) cout<<arg<<"\n"
#define prin2(arg1,arg2) cout<<arg1<<" "<<arg2<<"\n"
#define fill(arg,n) memset(arg,n,sizeof(arg))
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const int INF=1e+9;
const ll INFLL=1e+17;
int n;
int h[21];
int main(){
  cin>>n;
  rep(i,n) cin>>h[i];
  int res=1,maxh=h[0];
  rep1(i,n-1){
    if(h[i]>=maxh){
      maxh=h[i];
      res++;
    }
  }
  prin(res);
  return 0;
}
