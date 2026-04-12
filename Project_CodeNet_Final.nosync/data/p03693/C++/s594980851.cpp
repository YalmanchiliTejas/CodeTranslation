#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;i<(n);i++)

int main(){
  vector<int> x(3,0);
  REP(i,3) cin>>x.at(i);
  if((x.at(0)*100+x.at(1)*10+x.at(2))%4) cout<<"NO";
  else cout<<"YES";
}