#include<bits/stdc++.h>
using namespace std;

int main(){
  int a[12],str1,str2,str3;
  for(int i=0;i<12;i++){
    scanf("%d",&a[i]);
  }
  sort(a,a+12);
  str1 = a[0]-a[1] + a[2]-a[3];
  str2 = a[4]-a[5] + a[6]-a[7];
  str3 = a[8]-a[9] + a[10]-a[11];
  if(str1 == 0 && str2 == 0 && str3 == 0){
    printf("yes\n");
  } else{
    printf("no\n");
  }
  return 0;
}