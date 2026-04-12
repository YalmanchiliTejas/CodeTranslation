#include <bits/stdc++.h>
using namespace std;

long long calc(long long a, long long b, long long p){
  if (b == 0) return 1;
  else if(b % 2 == 0){
    long long d = calc(a, b/2, p);
    return (d * d) % p;
  }
  else return (a * calc(a, b - 1, p)) % p;
}

int main(){
  long long N, suma = 0, sumb = 0, ans, tmp;
  cin >> N;
  for (long long i = 0; i < N; i++){
    cin >> tmp;
    suma += tmp % (1000000000 + 7);
    sumb += (tmp % (1000000000 + 7) * tmp % (1000000000 + 7)) % (1000000000 + 7);
  }
  suma = ((suma % (1000000000 + 7))* (suma % (1000000000 + 7))) % (1000000000 + 7);
  long long tmp2 = (suma % (1000000000 + 7) - sumb % (1000000000 + 7)) % (1000000000 + 7);
  long long tmp3 = calc(2, 1000000000 + 5, 1000000000 + 7) % (1000000000 + 7);
  ans = tmp2 * tmp3 % (1000000000 + 7);
  if(ans < 0) ans += 1000000000 + 7;
  cout << ans << endl;
  return 0;
}
