#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  vector <long long>st(n);
  vector <long long> pst(n+1);
  for(int i =0;i<n;i++)
  {
    cin>>st[i];
  }
  pst[1] = st[0];
  pst[0] = 0;
  for(int i =2;i<n+1;i++)
  {
    pst[i] += pst[i-1] + st[i-1];
  }
  long long ans = 0;
  for(int i =0;i<n;i++)
  {
    long long p,q;
    p = st[i] % 1000000007;
    q = pst[n] - pst[i+1];
    q = q % 1000000007;
    ans += (p*q)%1000000007;
    ans = ans%1000000007;
  }
  cout<<ans;
  return 0;
}