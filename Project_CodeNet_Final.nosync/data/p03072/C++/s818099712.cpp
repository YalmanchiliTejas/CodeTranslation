#include<bits/stdc++.h>
using namespace std;
typedef signed long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
//vvi(n, vector<int>(m, -1))
 
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define all(a) (a).begin(), (a).end()
#define out(x) cout << (x) << endl;

int main(){
	int i,j,k,n,m,l,f,x,y,z; string s;
	cin >> n;
  int h[105];
  rep(i, n) cin >> h[i];

  f = 0;
  int count=0;
  rep(i, n){
    for(j=0;j<i;j++){
      if(h[i] < h[j]){
        f = 1;
        break;
      }
    }
    if(f==0) count++;
    f = 0;
  }

  out(count);
}