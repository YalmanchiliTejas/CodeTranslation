#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define REP(i,n) for(int i=0;i<(int)(n);i++)

using namespace std;
using pii=pair<int,int>;
pii x[200010];
int y[200010];
int main(){ _;
  int n;cin>>n;
  int n2=n/2;
  REP(i,n){
    cin>>x[i].first;
    x[i].second=i;
  }
  sort(x,x+n);
  REP(i,n2){
    y[x[i].second]=n2;
    y[x[i+n2].second]=n2-1;
  }
  REP(i,n){
    cout<<x[y[i]].first<<endl;
  }
}
