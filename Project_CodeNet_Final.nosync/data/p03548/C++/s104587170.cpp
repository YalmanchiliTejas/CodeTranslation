#include <bits/stdc++.h>
#define SORT(x) sort((x).begin(),(x).end())
#define ALL(x) (x).begin(),(x).end()
#define rep(i, n) for(int i = 0; i < n; i++)
#define reps(i, m, n) for(int i = m; i < n; i++)
#define repr(i, m, n) for(int i = m; i >= n; i--)
template<class T>bool chmax(T &a,const T &b){if(a<b){ a=b; return 1;} return 0;}
template<class T>bool chmin(T &a,const T &b){if(b<a){ a=b; return 1;} return 0;}
#define y0 y3487465 //j0
#define y1 y1347829 //j1
#define INF 1000000007 //4000000000000000037
#define PI (acos(-1))
#define MOD 1000000007
using namespace std;
typedef long long ll;



void Main(){

  int x,y,z;
  cin>>x>>y>>z;

  int ct=1;

  int now=2*z+y;

  rep(i,100000){
    now+=y+z;
    if(now>x) break;
    ct++;
  }

  cout<< ct<<"\n";
}

//-----------------------------------
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  Main();
}
//-----------------------------------
