#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
typedef long long ll;
#define rep(i,s,n) for(int i = s;i<n;i++)
#define repe(i,s,n) for(int i = s;i<=n;i++)
static const ll maxLL = (ll)1 << 62;
 
int main() {
   int x,y,z;
   cin>>x>>y>>z;
   
   cout<<(x-z)/(y+z)<<endl;
  return 0;
}