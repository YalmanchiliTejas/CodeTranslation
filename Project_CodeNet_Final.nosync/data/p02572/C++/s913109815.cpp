#include <bits/stdc++.h>
#define ll long long

const ll MOD = 1000000007;

using namespace std;

int main(){
  
  ll N;
  cin >> N;
  
  ll ar[N], reversePrefix[N];
  
  for (int i = 0; i < N; i++){ cin >> ar[i]; }
  
  reversePrefix[N-1] = ar[N-1];
  
  for (int i = N-2; i >= 0; i--)reversePrefix[i] =( (reversePrefix[i+1] + ar[i])%MOD);
  ll total = 0;
  
 
  
  for (int i = 0; i < N-1; i++) {total += ((ar[i]*reversePrefix[i+1])%MOD); total %= MOD;}
  cout << total << endl;
  
	

	return 0;
}