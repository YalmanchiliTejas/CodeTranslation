#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define rep(i,b) FOR(i,0,b)
#define INF mugen
#define dump(x) cerr<<#x<<"="<<x<<endl
#define all(a) (a).begin(),(a).end()
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;
typedef pair<int,int> P;
template <class T> void chmin(T & a, T const & b) { if (b < a) a = b; }
inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v; }
using ll = long long;
const ll mod = LLONG_MAX;

vector<int> vec;
int hai[212345];
int main(){
  int n;
  cin>>n;
  rep(i,n){
    int a;
    cin>>a;
    vec.push_back(a);
    hai[i]=a;
  }
  sort(all(vec));
  reverse(all(vec));

  int xa=vec[n/2-1];
  int xb=vec[n/2];



  rep(i,n){
    if(hai[i]>=xa){
      cout<<xb<<endl;
    }else{
      cout<<xa<<endl;
    }
  }


}
