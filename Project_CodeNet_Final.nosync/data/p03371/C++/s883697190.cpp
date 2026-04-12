#include<bits/stdc++.h>
using namespace std;
typedef signed long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
//vvi(n, vector<int>(m, -1))
 
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define ALL(a) (a).begin(), (a).end()
#define out(x) cout << (x) << endl;

int main(){
	int i,j,k,n,m,l,f,x,y,z; string s;
	int a, b, c;
  cin >> a >> b >> c >> x >> y;

  f = a*x + b*y;
  if(x >= y){
    f = min(f, c*y*2 + a*(x-y));
  }else{
    f = min(f, c*x*2 + b*(y-x));
  }
  f = min(f, 2*c*max(x, y));
  out(f);
}