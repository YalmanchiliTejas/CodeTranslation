#include <bits/stdc++.h>
/*#define fatafat 
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0);*/
#define int long long
#define MOD ((long long)(1e9) + 7)
#define excl(i, a, b) for (int i = a; i < b; i++)
#define incl(i, a, b) for (int i = a; i <= b; i++)
#define mp(a, b) make_pair(a, b)
#define ff first
#define ss second
#define PII pair<int, int>

using namespace std;

int binexp(int a, int b) {
  if (b) {
    if (b % 2)
      return a * binexp(a * a, b / 2);
    return binexp(a * a, b / 2);
  }
  return 1;
}

int modexp(int a, int b, int m) {
  if (b) {
    if (b % 2)
      return (a * modexp((a * a) % m, b / 2, m)) % m;
    return modexp((a * a) % m, b / 2, m);
  }
  return 1;
}

int mygcd(int a, int b) {
  if (b == 0)
    return a;
  return mygcd(b, a % b);
}

int euclidgcd, euclidx, euclidy;

void exteuclid(int a, int b) {
  if (b == 0) {
    euclidgcd = a;
    euclidx = 1;
    euclidy = 0;
  } else {
    exteuclid(b, a % b);
    int temp = euclidx;
    euclidx = euclidy;
    euclidy = temp - euclidy * (a / b);
  }
}

int modinv(int a, int m) {
  exteuclid(a, m);
  return (euclidx % m + m) % m;
}

int pmodinv(int a, int m) { return modexp(a, m - 2, m); }

bool checkprime(int a) {
  for (int i = 2; i * i <= a; i++)
    if (a % i == 0)
      return false;
  return true;
}

vector<bool> seive(int n) {
  vector<bool> ret(n + 1, true);
  ret[0] = ret[1] = false;
  for (int i = 2; i * i <= n; i++)
    if (ret[i])
      for (int j = i * i; j <= n; j += i)
        ret[j] = false;
  return ret;
}

vector<bool> seivelims(int l, int r) {
  vector<bool> ret(r - l + 1, true);
  for (int i = 2; i * i <= r; i++) {
    for (int j = max(i * i, ((l + i - 1) / i) * i); j <= r; j += i) {
      ret[j - l] = false;
    }
  }
  return ret;
}

vector<int> rootnfact(int n) {
  vector<int> ret;
  for (long i = 2; i * i <= n; i++)
    while (n % i == 0) {
      ret.push_back(i);
      n /= i;
    }
  if (n != 1)
    ret.push_back(n);
  return ret;
}

vector<int> prelognfact(int n) {
  vector<int> minprime(n + 1, 0);
  minprime[0] = minprime[1] = 0;
  for (int i = 2; i * i <= n; i++) {
    if (minprime[i] == 0) {
      for (int j = i * i; j <= n; j += i) {
        if (minprime[j] == 0)
          minprime[j] = i;
      }
    }
  }
  for (int i = 2; i <= n; i++)
    if (minprime[i] == 0)
      minprime[i] = i;
  return minprime;
}

vector<int> lognfact(int n, vector<int> minprime) {
  vector<int> ret;
  while (n != 1) {
    ret.push_back(minprime[n]);
    n /= minprime[n];
  }
  return ret;
}

int temp, temp1, temp2;

signed main() 
{ 
    //fatafat; 
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int max=-1,cnt=0;
    bool found=false;
    for(int i=0;i<n;i++)
    {
        found=false;
        for(int j=0;j<i;j++)
        {
            if(arr[j]>arr[i])
            {
                found=true;
                break;
            }
        }
        if(!found)
            cnt++;
    }
    cout<<cnt;
}