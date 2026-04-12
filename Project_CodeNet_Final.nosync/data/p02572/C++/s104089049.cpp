#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define M 1000000007
#define eb emplace_back
#define watch(x) cout << (#x) <<" is "<< x <<"\n";


using namespace std;
//const int N = 1e6;

int32_t main(){
  boost;
  int tc = 1; //cin >> tc;
  while(tc--)
  {
    int n; cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
      cin >> arr[i];
    int sum[n]; sum[n-1] = arr[n-1];
    for(int i=n-2; i>=0; i--)
      sum[i] = (arr[i] + sum[i+1]) %M;
    /*for(auto i : sum)
      cout << i <<" ";*/
    int ans = 0;
    for(int i=0; i<n-1; i++)
    {
      ans += ((arr[i]%M) * ((sum[i+1]%M))%M);
      ans %= M;
    }
    cout << ans <<"\n";

  }
}

