#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define pp pair<int,int>
#define ll long long
#define ld long double
int inf=100000000;
ll INF=4000000000000000000;
ll MOD=1000000007;



int main() {
  int n;
  cin >> n;
  vector<int> a(n),b(0);
  int ans=1;
  rep(i,n) cin >> a.at(i);
  reverse(a.begin(),a.end());
  b.push_back(a.at(0));
  int ma=a.at(0);
  for (int i=1;i<n;i++){
    int k=a.at(i);
    //cout << k << ma << endl;
    if (k>=ma){
      ans++;
      ma=k;
      b.push_back(k);
      continue;
    }
    auto it=upper_bound(b.begin(),b.end(),k);
    
      b.at(it-b.begin())=k;
      if (it-b.begin()==b.size()-1){
        ma=b.at(b.size()-1);
      }
  }
  cout << ans << endl;
  }