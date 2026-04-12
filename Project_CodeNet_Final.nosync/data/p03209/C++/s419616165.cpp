#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll x;

ll total[55];
ll patty[55];

ll solve(int n, ll x){
  ll res=0;
  if (n == 0) return (x >= 0) ? 1 : 0;
  ll center = total[n] / 2;
  if(x==center){
    res += patty[n-1] + 1;
  }else if (x < center) {
    res += solve(n - 1, x - 1);
  } else {
    res += 1 + patty[n-1] + solve(n - 1, x - center - 1);
  }
  return res;
}

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

  cin>>n;
  cin>>x;
  x--;
  total[0]=1;
  patty[0]=1;
  for(int i=1;i<=n;i++){
    total[i] = total[i - 1] * 2 + 3;
    patty[i] = patty[i-1]*2 + 1;
  }
  ll res=solve(n, x);
  cout<<res<<endl;

  return 0;
}
