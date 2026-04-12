#include<cstdio>
#include<vector>
#include<stack>
using namespace std;

typedef pair<int,int> pii;

bool solve(){
  int n;
  stack<pii> stone;
  scanf("%d",&n);
  if(n==0) return false;
  for(int i=0;i<n;i++){
    int color;
    scanf("%d",&color);
    if(i&1){
      pii p = stone.top(); stone.pop();
      if(p.first==color){
        p.second++;
        stone.push(p);
      }else{
        p.first ^= 1;
        p.second++;
        if(!stone.empty()&&stone.top().first==p.first){
          pii p1 = stone.top(); stone.pop();
          p.second += p1.second;
          stone.push(p);
        }
        else stone.push(p);
      }
    }else{
      if(i){
        pii p = stone.top(); stone.pop();
        if(p.first==color){
          p.second++;
          stone.push(p);
        }else{
          stone.push(p);
          stone.push(pii(color,1));
        }
      }
      else stone.push(pii(color,1));
    }
  }
  int ans = 0;
  while(!stone.empty()){
    if(stone.top().first==0) ans += stone.top().second;
    stone.pop();
  }
  printf("%d\n",ans);
  return true;
}

int main(){
  while(true) if(!solve()) return 0;
}