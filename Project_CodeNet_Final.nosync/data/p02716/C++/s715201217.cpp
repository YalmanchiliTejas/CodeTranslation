#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

ll n;
ll a[200010];
ll sum[200010];
ll f[200010];
int main()
{
  cin >> n;
  for(int i = 1; i <= n; i++)
  {
    cin >> a[i];
  }
  sum[1] = a[1];
  for(int i = 2; i <= n; i++)
   {
		sum[i] = sum[i-2] + a[i];
   }
    for(int i = 2; i <= n; i++)
      {
        if(i & 1)
        {
				f[i] = max(f[i-2] + a[i], f[i-1]);
        }
        else
        {
			f[i] = max(f[i-2] + a[i], sum[i-1]);
        }
      }
      cout << f[n] << endl;
	return 0;
}