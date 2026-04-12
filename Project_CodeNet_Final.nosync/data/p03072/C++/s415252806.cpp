#include<bits/stdc++.h>
using namespace std;



int main(){
  int n,ans=0;
  scanf("%d",&n);
  int a[n];
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  for(int i=0;i<n;i++){
    bool val=true;

    for(int j=0;j<i;j++){
      if(a[j]>a[i])
        val=false;
    }
    if(val){
      ans+=1;
    }
  }
  printf("%d\n",ans);
  return 0;
}