#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod=1e9+7;
int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  int s=0;
  int sol=0;
  for(int& x:a)cin>>x;
  for(int x:a){
    sol=((ll)sol+(ll)x*(ll)s)%mod;
    s=(s+x)%mod;
  }
  cout<<sol;
}
