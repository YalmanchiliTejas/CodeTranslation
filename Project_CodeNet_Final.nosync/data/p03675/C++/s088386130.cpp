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

int a[212345];
int main(){
  int n;
  cin>>n;
  FOR(i,1,n+1)cin>>a[i];
  if(n%2==0){
    for(int i=n;i>=1;i-=2){
      cout<<a[i]<<' ';
    }
    for(int i=1;i<=n;i+=2){
      cout<<a[i]<<' ';
    }
    cout<<endl;
  }else{
    for(int i=n;i>=1;i-=2){
      cout<<a[i]<<' ';
    }
    for(int i=2;i<=n;i+=2){
      cout<<a[i]<<' ';
    }
    cout<<endl;
  }

}
