#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<numeric>
#include<utility>
#include<unordered_map> //hash map
#include<cmath>

#define rep(i,a,n) for(int (i)=(a);(i)<(n);(i)++)
#define rrep(i,a,n) for(int (i)=(a);(i)>=(n);(i)--)

#define INF 10000007

typedef  long long ll;

using namespace std;

ll gcd(ll a,ll b){
    if (b==0)return a;
    return gcd(b,a%b);
}

ll deg(int i){
  ll ret = 1;
  while(i != 0){
    if(i/10 == 0){
      break;
    }
    i/=10;
  }
  return i;
}

void solve(){
  string s;
  cin >> s;
  if(s=="BBB"||s=="AAA") cout << "No" << endl;
  else cout << "Yes" << endl;
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}
