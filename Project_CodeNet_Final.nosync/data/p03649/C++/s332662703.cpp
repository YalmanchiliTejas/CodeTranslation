#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
  ll N;
  ll A[55];
  ll cnts[55] = {};
  
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }
  
  ll cnt = 0;
  bool flag = true;
  while(flag) {
    flag = false;
    for(int i = 0; i < N; i++) {
      if((A[i] + cnt - cnts[i]) / N > 0) {
	ll div = (A[i] + cnt - cnts[i]) / N;
	flag = true;
	cnt += div;
	cnts[i] += div;
	A[i] -= div * N;
      }
    }
  }

  cout << cnt << endl;
  
  return (0);
}

    
    