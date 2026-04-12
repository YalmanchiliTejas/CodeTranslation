#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

vector<list<int>> e;

int dfs(int n,int par){
  int ans=0,re;
  for(auto itr=e[n].begin();itr!=e[n].end();itr++){
    if((*itr)!=par){
      re=dfs(*itr,n);
      if(re==0) ans++;
      else if(re>1){
        ans=2;
        break;
      }
    }
  }
  return (ans>1?2:ans);
}

int main(){
  int n;
  cin >> n;
  if(n==2){
    cout << "Second" << endl;
    return 0;
  }
  e=vector<list<int>>(n);
  int a,b;
  vector<int> d(n,0);
  for(int i=0;i<n-1;i++){
    cin >> a >> b;
    e[--a].push_back(--b);
    e[b].push_back(a);
    d[a]++,d[b]++;
  }
  int num1=-1,num2;
  for(int i=0;i<n;i++){
    if(d[i]>1){
      num1=i;
      num2=num1;
    }
  }
  if(num2==-1) cout << "First" << endl;
  else cout << (dfs(num1,-1)>1||dfs(num2,-1)>1?"First":"Second") << endl;
  return 0;
}
