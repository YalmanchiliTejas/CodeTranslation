#include<bits/stdc++.h>
using namespace std;
int main(){
  int a[5],b[5],num;
  while(cin >> a[0] >> b[0],a[0]!=0||b[0]!=0){
    num = 0;
    for(int i=1;i<5;i++){
      cin >> a[i] >> b[i];
      if(a[num]+b[num] < a[i]+b[i]) num = i;
    }
    printf("%c %d\n",'A'+num,a[num]+b[num]);
  }
  return(0);
}

