#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repp(i, n, m) for (int i = (int)(n); i < (int)(m); i++)
#define rrep(i, n, m) for (int i = n; i >= m; i--)
#define ALL(a) (a).begin(), (a).end()
#define p(a, b) printf(a, b);
#define c(s) cout << (s) << endl;
#define yes cout << "Yes" << endl;
#define no cout << "No" << endl;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define cyn(c) cout << (c ? "Yes" : "No") << endl;
#define cYN(c) cout << (c ? "YES" : "NO") << endl;
#define pyn(c) printf("%s\n", c ? "Yes" : "No");
#define pYN(c) printf("%s\n", c ? "YES" : "NO");
#define INF 1e18
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<LL, LL> P;
template <class T>
bool contain(const std::string &s, const T &v)
{
  return s.find(v) != std::string::npos;
}
ULL mod = 1e9 + 7;

int main(){
    int n,flag=0; cin>>n;
    int h[25]={},ans=0; rep(i,n)cin>>h[i];
    for(int i=0; i<n; i++){
      int now = h[i];
      // cout << "now: " << now << endl;
      for(int j=0; j<=i; j++){
        // cout<<"h[j]: "<<h[j]<<endl;
        if(now < h[j]){
          flag=1;
        }
      }
      if(flag){
        flag=0;
        continue;
      }else{
        ans++;
      }
    }
    cout<<ans<<endl;
}
