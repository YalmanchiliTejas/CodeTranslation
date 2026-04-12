#include <bits/stdc++.h>
#define REP(i,n) for(ll i = 0; i < (ll)n; i++)
#define FOR(i,a,b) for (ll i=(a);i<(ll)b; i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define INF 1000000000000000
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
using namespace std;
typedef long long ll;
typedef double db;
typedef string str;
typedef pair<ll,ll> p;
const int MOD = 1000000007;

void print(const std::vector<int>& v)
{
  std::for_each(v.begin(), v.end(), [](int x) {
    std::cout << x << " ";
  });
  std::cout << std::endl;
}

int main ()
{
  int N;cin>>N;
  vector<ll> H(N);
  REP(i,N) cin>>H[i];
  int cnt = 1;
  for (int i = 1; i < N; i++)
  {
    int flag = 0;
    for (int j = 0; j < i; j++)
    {
      if(H[j]>H[i]){
          flag++;
          }
    }
    if(flag==0){
      cnt++;
    }
  }
  
  cout<<cnt<<endl;
  return 0;
}