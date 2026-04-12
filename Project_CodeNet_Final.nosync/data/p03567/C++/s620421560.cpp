#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <queue>

using namespace std; using ll=long long; using ld=long double; using P=pair<ll,ll>; const int INF=1e9; const ll LINF=1e18;

int main(){
  string s; cin>>s;
  for(int i=0;i<s.size()-1;i++) {
    if (s[i]=='A'&&s[i+1]=='C') {
      cout<<"Yes"<<endl;
      return 0;
    }
  }
  cout<<"No"<<endl;
}