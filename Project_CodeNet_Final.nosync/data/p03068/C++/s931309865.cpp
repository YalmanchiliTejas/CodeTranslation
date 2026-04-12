#include <bits/stdc++.h>
#define ll long long
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mp make_pair
#define pb push_back
#define mod 1000000007

using namespace std;

int main() {
    IOS;
  ll n,k;
  cin>>n;
  string s;
  cin>>s;
  cin>>k;
  for(int y=0;y<s.length();y++)
  {
      if(s[y]!=s[k-1])
        cout<<"*";
      else
        cout<<s[y];
  }
    return 0;
}
