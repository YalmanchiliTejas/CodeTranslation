#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include <numeric>
using namespace std;
#define INF (1 << 30) - 1
#define LINF 1LL << 60
const int MOD = 1000000007;
using ll = long long;
using P = pair<int, int>;

int n;
vector<ll> a;

ll memo[3050][3050];
ll rec(int i, int j){
	if(memo[i][j] != -1)return memo[i][j];
	if(j - i < 0)return 0; 

	bool flg = (i + j) % 2 == (n - 1) % 2; 
	if(flg)return memo[i][j] = max(rec(i + 1, j) + a[i], rec(i, j - 1) + a[j]);
	else return memo[i][j] = min(rec(i + 1, j), rec(i, j - 1));
}

int main(){
  cin >> n;
  a.resize(n);
  for(int i = 0; i < n; ++i){
  	cin >> a[i];
  }

  ll sum = accumulate(a.begin(), a.end(), 0LL);
  fill((ll*)memo, (ll*)memo + sizeof(memo) / sizeof(ll), -1);

  cout << 2 * rec(0, n - 1) - sum << endl;

  return 0;
}
