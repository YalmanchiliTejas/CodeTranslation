#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string.h>
#include<cmath>
#include<vector>
#include<queue>

using namespace std;

#define INF 2<<29

int main(){
  int n,h[100],temp=0,ans=0;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&h[i]);
  }

  for(int i=0;i<n;i++){
    if(temp<=h[i]){
      ans++;
      temp=h[i];
    }
  }

  printf("%d\n",ans);
  
  return 0;
}
