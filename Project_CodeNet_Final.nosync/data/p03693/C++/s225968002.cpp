#include <bits/stdc++.h>
#define SORT(x) sort(x.begin(),x.end())
#define ALL(x) x.begin(),x.end()
#define deb(x) cout<<#x<<"="<<x<<endl
#define rep(i, n) for(int i = 0; i < n; i++)
#define reps(i, m, n) for(int i = m; i < n; i++)
#define repr(i, m, n) for(int i = m; i >= n; i--)
#define INF 1000000000000000007
#define PI (acos(-1))
#define MOD 1000000007
using namespace std;
typedef long long ll;


void Main(){

  int r,g,b;
  cin>>r>>g>>b;
  cout<< ( ((g*10)+b)%4 ? "NO" : "YES" )<<"\n";
}
//-----------------------------------
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  Main();
}
//-----------------------------------
