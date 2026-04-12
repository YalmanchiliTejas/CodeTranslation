#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll a[3005];
ll mo[3005][3005];
int n;
ll dp(int l,int r);
int main()
{


  cin >> n;

  for(int i=0; i<n; i++) cin >> a[i];

  memset(mo, -1, sizeof(mo));
  cout << dp(0,n-1) << endl;

  return 0;
}

ll dp(int l, int r){

  if(l == r) return a[l];
  if(mo[l][r] != -1) return mo[l][r];

  return mo[l][r] = max(a[l] - dp(l+1,r), a[r] - dp(l,r-1));

}
