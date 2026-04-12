#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<vector>
typedef long long int ll;
#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOR_IN(i, a, b) for(int i = (a); i < (b); i++)
#define BETWEEN(x, a, b) ((x) >= (a) && (x) <= (b))
#define BIT(b, i) (((b) >> (i)) & 1)
#define LOG_F 1
#define LOG(...) if(LOG_F) fprintf(stderr, __VA_ARGS__)

using namespace std;

ll pow(int x, int n){
  return n == 0 ? 1 : x * pow(x, n - 1);
}
/*

 */
int n, h[20];
int main()
{
  cin >> n;
  int ans = 0;
  for (size_t i = 0; i < n; i++)
  {
    cin >> h[i];
    bool f = true;
    for (size_t j = 0; j < i; j++)
    {
      if (h[j]>h[i]) {
        f = false;
      }

    }
    if (f)
    {
      ans++;
    }
  }
  
  cout << ans << endl;
  return 0;
}
