#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define erep(i,a,n) for(int i = a;i<=n;i++)
typedef long long ll;
#define int long long
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vdouble vector<double>
#define vll vector<ll>:
#define vbool vector<bool>
#define INF 1101010101010101010
#define MOD 1000000007
#define P = pair<int,int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

signed main(){
  int n;
  cin >> n;
  vint A(n);
  rep(i,0,n){
    cin >> A[i];
  }
  deque<int> d;
  rep(i,0,n){
    int key = lower_bound(d.begin(),d.end(),A[i]) - d.begin();
    if(key == 0){
      d.push_front(A[i]);
    }
    else{
      d[key-1] = A[i]; 
    }
  }
  cout << d.size() << endl;
}