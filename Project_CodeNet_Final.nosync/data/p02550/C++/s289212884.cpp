#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
#define seive_len 1000001

typedef long long int lli;

bool seive[seive_len];
const int MOD = 1000000007;
lli primeSeive[seive_len];

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

lli ncr(lli n, lli r) {
  lli res = 1;
  if(r > n-r)
    r = n-r;
  
  for(lli i=0;i<r;i++) {
    res *= (n-i);
    res /= (i+1);
  }
  return res;
}

lli ncrMODp(lli n, lli r) {
  if(r > n-r)
    r = n-r;
  lli prow[r+1];
  memset(prow, 0, sizeof(prow));
  prow[0] = 1;
  for(lli i=1;i<=n;i++) {
    for(lli j=min(i, r);j>0;j--) {
      prow[j] = (prow[j]+prow[j-1])%MOD;
    }
  }
  return prow[r];
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

lli fastPowerMODp(lli a, lli b) {
  a %= MOD;
  lli res = 1;
  while(b) {
    if(b%2 == 1)
      res = (res*a)%MOD;
    a = (a*a)%MOD;
    b >>= 1;
  }
  return res;
}

void multiply(lli a[][2], lli b[][2]) {
  lli res[2][2];
  memset(res, 0, sizeof(res));
  for(lli i=0;i<2;i++) {
    for(lli j=0;j<2;j++) {
      for(lli k=0;k<2;k++) {
        res[i][j] += a[i][k]*b[k][j]%MOD;
      }
    }
  }
  for(lli i=0;i<2;i++)
    for(lli j=0;j<2;j++)
      a[i][j] = res[i][j];
}

void matrixExpo(lli a[][2], lli n) {
  if(n == 0 || n == 1)
    return;
  lli b[][2] = {{1,1}, {1,0}};
  matrixExpo(a, n/2);
  multiply(a, a);
  if(n%2)
    multiply(a, b);
}

void makeSeive() {
  for(lli i=2;i*i<=seive_len;i++) {
    if(seive[i]) {
      for(lli j=i*i;j<=seive_len;j+=i)
        seive[j] = false;
    }
  }
}

void makePrimeSeive() {
  for(lli i=1;i<seive_len;i++)
    primeSeive[i] = i;
  for(lli i=4;i<seive_len;i+=2)
    primeSeive[i] = 2;
  for(lli i=3;i*i<seive_len;i++) {
    if(primeSeive[i] == i) {
      for(lli j=i*i;j<seive_len;j+=i) {
        if(primeSeive[j] == j)
          primeSeive[j] = i;
      }
    }
  }
}

bool isPrime(lli n) {
  for(lli i=2;i<=sqrt(n);i++) {
    if(n%i == 0)
      return false;
  }
  return true;
}

void getInput(vector<lli>& a, lli n) {
  lli x;
  for(lli i=0;i<n;i++) {
    cin >> x;
    a.push_back(x);
  }
}

void testCase() {
  lli i, x, n, m1;
  cin >> n >> x >> m1;
  lli r = x%m1;
  lli sum = r;
  lli p = r;
  unordered_map<lli, lli> m;
  vector<lli> temp;
  temp.push_back(sum);
  m[p] = 0;
  for(i=1;i<n;i++) {
    p = p%m1;
    p *= p;
    lli y = p%m1;
    if(m.find(y) == m.end()) {
      m[y] = i;
      sum += y;
      temp.push_back(sum);
    }
    else {
      lli z = m[y];
      lli g = i-z;
      lli mul = (n-z)/g;
      lli rem = (n-z)%g;
      if(z == 0) {
        lli t = sum*mul;
        if(rem == 0)
          sum = t;
        else
          sum = t + temp[rem-1];
        break;
      }
      lli t = (sum-temp[z-1])*mul;
      sum = t + temp[z-1+rem];
      break;
    }
  }
  cout << sum;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	lli t=1;
	// cin >> t;
  // makePrimeSeive();
  // FILE* fp;
  // fp = fopen("out.txt", "w");
	for(lli i=1;i<=t;i++) {
    // fprintf(fp, "Case #%d:\n", i);
    // cout << "Case #" << i << ":" << ' ';
		testCase();
    cout << '\n';
	}
	return 0;
}