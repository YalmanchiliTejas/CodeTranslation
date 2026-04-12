#include<bits/stdc++.h>
#define int long long int
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef vector<PII> VP;
typedef pair<PII, int> PPI;
typedef pair<int, PII> PIP;

const int INF = 3e18;

int n, a[200010];
VI b;

signed main()
{
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }

  if(n % 2){
    for(int i = n; i > 0; i -= 2){
      b.PB(a[i]);
    }
    for(int i = 2; i <= n; i += 2){
      b.PB(a[i]);
    }
  }

  else{
    for(int i = n; i > 0; i -= 2){
      b.PB(a[i]);
    }
    for(int i = 1; i <= n; i += 2){
      b.PB(a[i]);
    }
  }

  for(int i = 0; i < n; i++){
    cout  << b[i] << " ";
  }
  cout << endl;
  return 0;
}
