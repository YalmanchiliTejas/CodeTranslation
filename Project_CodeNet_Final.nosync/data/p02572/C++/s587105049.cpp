#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define PI 3.14159265
#define seive_len 1000001

bool seive[seive_len];
int primeSeive[seive_len];

typedef long long int lli;

lli gcd(lli a, lli b) {
  if(b == 0)
    return a;
  return gcd(b, a%b);
}

lli lcm(lli a, lli b) {
  lli gcd_ = gcd(a, b);
  lli lcm_ = (a*b)/gcd_;
  return lcm_;
}

lli fastPower(lli a, lli b) {
  lli res=1;
  while(b > 0) {
    if(b&1)
      res *= a;
    a *= a;
    b >>= 1;
  }
  return res;
}

lli fastPowerM(lli a, lli b, lli mod) {
  a %= mod;
  lli res = 1;
  while(b) {
    if(b%2 == 1)
      res = (res*a)%mod;
    a = (a*a)%mod;
    b >>= 1;
  }
  return res;
}

void multiply(lli a[][2], lli b[][2], int mod) {
  int res[2][2];
  memset(res, 0, sizeof(res));
  for(int i=0;i<2;i++) {
    for(int j=0;j<2;j++) {
      for(int k=0;k<2;k++) {
        res[i][j] += a[i][k]*b[k][j]%mod;
      }
    }
  }
  for(int i=0;i<2;i++)
    for(int j=0;j<2;j++)
      a[i][j] = res[i][j];
}

void matrixExpo(lli a[][2], lli n, int mod) {
  if(n == 0 || n == 1)
    return;
  lli b[][2] = {{1,1}, {1,0}};
  matrixExpo(a, n/2, mod);
  multiply(a, a, mod);
  if(n%2)
    multiply(a, b, mod);
}

void makeSeive() {
  for(int i=2;i*i<=seive_len;i++) {
    if(seive[i]) {
      for(int j=i*i;j<=seive_len;j+=i)
        seive[j] = false;
    }
  }
}

void makePrimeSeive() {
  for(int i=1;i<seive_len;i++)
    primeSeive[i] = i;
  for(int i=4;i<seive_len;i+=2)
    primeSeive[i] = 2;
  for(int i=3;i*i<seive_len;i++) {
    if(primeSeive[i] == i) {
      for(int j=i*i;j<seive_len;j+=i) {
        if(primeSeive[j] == j)
          primeSeive[j] = i;
      }
    }
  }
}

bool isPrime(lli n) {
  for(int i=2;i<=sqrt(n);i++) {
    if(n%i == 0)
      return false;
  }
  return true;
}

void getInput(vector<lli>& a, int n) {
  lli x;
  for(int i=0;i<n;i++) {
    cin >> x;
    a.push_back(x);
  }
}

void replaceSpace(string& s) {
  for(int i=0;s[i];i++) {
    if(s[i] == ' ')
      s.replace(i, 1, "%20");
  }
}


void testCase() {
  lli i, n;
  cin >> n;
  vector<lli> a;
  getInput(a, n);
  vector<lli> b(n-1);
  lli sum = 0;
  for(i=n-1;i>=1;i--) {
    sum += a[i];
    b[i-1] = sum%MOD;
  }
  lli res = 0;
  for(i=0;i<n-1;i++) {
    res += ((lli)(a[i]%MOD*b[i]%MOD)%MOD);
    res %= MOD;
  }
  cout << res;
}

int main() {
	int t=1;
	// cin >> t;
  // makePrimeSeive();
  // FILE* fp;
  // fp = fopen("out.txt", "w");
	for(int i=1;i<=t;i++) {
    // fprintf(fp, "Case #%d:\n", i);
    // cout << "Case #" << i << ":" << ' ';
		testCase();
    cout << '\n';
	}
	return 0;
}