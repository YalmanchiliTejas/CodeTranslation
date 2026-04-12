#include <bits/stdc++.h>
using namespace std;

typedef long long  ll;

ll MOD = 1000000007;
ll INF = 100000000000000000;
double PI = 3.1415926535;

template<typename T>
void remove(std::vector<T>& vector, unsigned int index)
{
    vector.erase(vector.begin() + index);
}

using Graph = vector<vector<int>>;

int main(){
  ll N;cin >> N;
  vector<ll> A(N);
  for(int i = 0;i < N;i++){
    cin >> A[i];
  }
  ll dp[100010];
  fill(dp,dp+100010,INF);
  for(int i = 0;i < N;i++){
    *upper_bound(dp,dp+N,-A[i]) = -A[i];
  }
  cout << lower_bound(dp,dp+N,INF) - dp << endl;
}
