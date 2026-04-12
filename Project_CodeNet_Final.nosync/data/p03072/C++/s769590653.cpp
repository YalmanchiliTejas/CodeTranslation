#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N; cin >> N; int H[N]; int Max = 0;
  int ans = 0;
  for(int i = 0; i < N; i++){
    cin >> H[i];
    if(H[i] >= Max) ans++;
    Max = max(Max, H[i]);
  }
  cout << ans;
  return 0;
}