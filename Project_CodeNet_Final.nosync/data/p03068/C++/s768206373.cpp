#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;
#define MOD 1000000007

template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline T gcd(T a,T b){T c;while(b!=0){c=a%b;a=b;b=c;}return a;}
template<class T> inline T lcm(T a,T b){return a*b/gcd(a,b);}

const int INF=1e9;
const double eps=0.0000000001;



int main(){
  int n,k;
  string s;
  cin >> n >> s >> k;
  FOR(i,n){
    if(s[i]!=s[k-1]){
      s[i]='*';
    }
  }
  cout << s << endl;
}
