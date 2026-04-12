#include<bits/stdc++.h>

#define rep(i, a, n)  for(ll i=a; i<n; i++)
#define per(i, a, n)  for(ll i=n-1; i>=a; i--)
#define fill0(n)  setfill('0') << right << setw(n)
#define all(x)  (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define LONGMAX 1e18
#define INTMAX 1000000000
using namespace std;
typedef long long ll;
typedef pair<ll,ll> p;

int n;
vector<int> h;

int main(){
  cin >> n;
  rep(i,0,n){
    int tmp;
    cin >> tmp;
    h.push_back(tmp);
  }
  int ans = 0;
  int tmp_max = 0;
  for (int i = 0; i < h.size(); i++)
  {
    if(h[i]>= tmp_max){
      ans++;
      tmp_max = h[i];
    }
  }
  cout << ans << endl;
  
}