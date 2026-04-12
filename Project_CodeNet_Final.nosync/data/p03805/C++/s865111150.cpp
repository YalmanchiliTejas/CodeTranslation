#include<bits/stdc++.h>
using namespace std;
long move(int cur,vector<set<int> >hen,vector<bool>went,int n,int m){
  int chk = 1;
  int i;
  went[cur]=true;
  for(i=1;i<=n;i++){
    if(!went[i])chk = 0;
  }
  long ans = 0;
  if(chk==1)return 1;
  else{
    for(auto i : hen[cur]){
      if(!went[i])ans+=move(i,hen,went,n,m);
    }
    return ans;
  }
}


int main(){
  int n,m;
  cin >> n >> m;
  int i;
  int a,b;
  vector<set<int> >hen(n+1);
  for(i=0;i<m;i++){
    cin >> a >> b;
    hen[a].insert(b);
    hen[b].insert(a);
  }
  vector<bool>went(n+1);
  cout << move(1,hen,went,n,m);

}
