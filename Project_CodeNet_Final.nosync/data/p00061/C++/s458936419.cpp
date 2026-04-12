#include<bits/stdc++.h>
using namespace std;
int main(){
  pair<int,int>a[1000];
  int c=0,t[1000];
  char cc;
  while(1){
    scanf("%d,%d",&a[c].second,&a[c].first);
      c++;
      if(a[c-1].first==0&&a[c-1].second==0)goto L;
    }
  L:c--;
  stable_sort(a,a+c);
  int r=1;
  t[a[c-1].second]=1;
  for(int i=c-2;i>=0;i--){
    if(a[i+1].first!=a[i].first){
      t[a[i].second]=(++r);
    }
    else{
      t[a[i].second]=r;
    }
  }
  while(cin>>c)cout<<t[c]<<endl;
}