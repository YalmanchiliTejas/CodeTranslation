#include <bits/stdc++.h>
#include <cmath>
#include <map>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,a,n) for(int i=a;i<n;i++)
#define been(ix) (ix).begin(),(ix).end()
using namespace std;
typedef long long ll; 
typedef vector<int> vi;
typedef vector<long long> vl;
const ll INFL = 1e18;
const int INF = 1001001001; 
typedef pair<int,int> P;
#define foreach(ix,i) for(auto& (ix) : (i))
typedef long double ld;

int main(){
 int a,b,c,x,y;
 cin>>a>>b>>c>>x>>y;
 int ans =INF;
 int simple =a*x+b*y;
 int x_cnt = x*2*c;
 if(y>x)x_cnt+=min(c*(y-x)*2,b*(y-x));
 ans = min(simple,x_cnt);
 int y_cnt = y*2*c;
 if(x>y)y_cnt+=min(c*(x-y)*2,a*(x-y));
 ans=min(ans,y_cnt);
 cout<<ans<<endl;
}