#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,c,bef,cou,ans;
  vector<int> go[2];
  while(scanf("%d",&n),n!=0){
    cou = 0;
    ans = 0;
    for(int i=0;i<n;i++){
      scanf("%d",&c);
      if(i == 0) bef = c;
      if(bef == c) cou++;
      else {
	go[bef].push_back(cou);
	cou = 1;
	if(i%2 == 1 && go[c].empty()){
	  cou += go[bef][0];
	  go[bef].pop_back();
	} else if(i%2 == 1){
	  cou += go[c][go[c].size()-1]+go[bef][go[bef].size()-1];
	  go[c].pop_back();
	  go[bef].pop_back();
	}
      }
      bef = c;
    }
    go[c].push_back(cou);
    for(int i=go[0].size()-1;i>=0;i--){
      ans += go[0][i];
      go[0].pop_back();
    }
    printf("%d\n",ans);
    go[1].clear();
  }
  return (0);
}