//Code by Mukul Totla
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{   
  #ifndef ONLINE_JUDGE 
  freopen ("input.txt", "r", stdin);
  freopen ("output.txt", "w", stdout);
  #endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n,i;
  cin>>n;
  if(n>=30)
    cout<<"Yes";
  else
    cout<<"No";

  return 0;
}