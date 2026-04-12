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

int n;
string k;

int dp[110][3][5];

int res(int i = 0,bool under = false,int zero = n){
  if(zero == 0) return 1;
  if(i >= k.size()) return 0;
  
  int &tmp = dp[i][under][zero];
  if(tmp > 0) return tmp;

  tmp = 0;

  if(under){
    tmp += res(i+1,true,zero);
    tmp += res(i+1,true,zero-1)*9;
  }
  else{
    if(k[i] == '0'){
      tmp += res(i+1,false,zero);
    }
    else{
      tmp += res(i+1,true,zero);
      tmp += res(i+1,false,zero-1);
      tmp += res(i+1,true,zero-1)*(k[i] - '1');
    }
  }
  return tmp;
}

signed main(){
  cin >> k >> n;
  int l = k.size();
  cout << res() << endl;
}