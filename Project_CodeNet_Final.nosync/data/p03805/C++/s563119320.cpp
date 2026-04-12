#include <bits/stdc++.h>
using namespace std;
#define FOR(i,l,n) for(int i=l; i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)

int main(){
  int n,m; cin>>n>>m;
  vector<int> a(m),b(m);
  REP(i,m) cin>>a[i]>>b[i];
  
  vector<int> order(n);
  REP(i,n) order[i]=i+1;

  int cnt=0;
  do{
    vector<int> chk(n-1,0);
	REP(i,n-1){
      REP(j,m){
        if((min(order[i],order[i+1])==min(a[j],b[j]))
           &&(max(order[i],order[i+1])==max(a[j],b[j]))){
          chk[i]=1;
        }
      }
    }
    int flag=1;
    REP(i,n-1){
      flag*=chk[i];
    }
    if(flag==1) cnt++;
  } while (next_permutation(order.begin()+1, order.end()));
  
  cout << cnt << endl;
}