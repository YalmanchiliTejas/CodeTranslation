#include <bits/stdc++.h>

using namespace std;

#define INF 210000000
#define int long long

int gcd(int a, int b) {
  int amari = a % b;
  int c = b;
  if (amari == 0) {
    return b;
  } else {
    return gcd(b, amari);
  }
}

int lcm(int a, int b) { return a * b / gcd(a, b); }

signed main() {
		char a;
		cin >> a;
		if(a == 'a' || a == 'o' || a == 'e' || a == 'i' || a == 'u') cout << "vowel" << endl;
		else cout << "consonant" << endl;
}

