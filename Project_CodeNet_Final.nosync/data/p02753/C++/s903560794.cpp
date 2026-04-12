#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e5 + 10;
#define fi first
#define se second
#define pb push_back
char a[N];
int main() {
  ios::sync_with_stdio(false);
  cin>>a+1;int l=0,r=0;
  for(int i=1;i<=3;i++){
    if(a[i]=='A')l++;
    else r++;
  }
  if(l && r)cout<<"Yes\n";
  else cout<<"No\n";
  return 0;
}