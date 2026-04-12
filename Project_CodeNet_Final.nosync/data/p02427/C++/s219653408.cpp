#include<bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

#define MAX 100005
#define INF 1001001001

int main(int, char**)
{
  int n;
  cin >> n;

  rep(i,1<<n) {
    cout << i << ":";
    rep(j,n) if (i&(1<<j)) cout << " " << j;
    cout << endl;
  }

  return 0;
}

