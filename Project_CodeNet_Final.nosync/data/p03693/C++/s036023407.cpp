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
int main(){
  int r,g,b;
  cin>>r>>g>>b;
  int num=100*r+10*g+b;
  if(num%4==0) prin("YES");
  else prin("NO");

  return 0;
}
