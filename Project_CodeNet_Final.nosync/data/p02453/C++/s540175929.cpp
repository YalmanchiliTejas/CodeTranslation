#include <bits/stdc++.h>
#define r(i,n) for(int i = 0; i<n; i++)
typedef long long ll;
using namespace std;

int main(){
  int n,m,a;
  cin >> n;
  vector<int> v(n);
  r(i,n){
    cin >> v.at(i);
  }
  cin >> m;
  while(m--){
    cin >> a;
    cout << lower_bound(v.begin(),v.end(),a)-v.begin()<<endl;
  }
  
}
