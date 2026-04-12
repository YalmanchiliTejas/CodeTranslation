#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first
#define se second
#define pi 3.1415926535
#define mod1 1000000007
#define mod2 1000000009
#define mp make_pair
#define no_of_digits(n) floor(log10(n)) + 1
#define lcm(a, b) (a/__gcd(a,b)*b)

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  string s;
  cin >> s;
  int ok = 0;
  for(int i =0; i < 2; i++){
    for(int j = i+1; j < 3; j++){
      if(s[i] != s[j]){
        ok = 1;
        break;
      }
    }
  }

  cout << (ok?"Yes":"No") << '\n';

  return 0;
}

