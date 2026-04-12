#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int n;
int ans;//合計点
int top,dow,rig;//上の面、下の面、右の面の出目
string sousa;
int main(){
  while(true){
  scanf("%d",&n);//操作回数の入力
  if(n ==0)
    break;
  top = 1;
  dow = 2;
  rig = 3;
  ans = 1;
  int temp1,temp2,temp3;
  for(int i= 0;i < n;i++){
    cin >> sousa;
    temp1 = top;
    temp2 = dow;
    temp3 = rig;

    if(sousa == "North"){
      top = temp2;
      dow = 7-temp1;
      rig = temp3;
      ans +=top;
    }else if(sousa =="East"){
      top = 7-temp3;
      dow = temp2;
      rig = temp1;
      ans +=top;
    }else if(sousa =="West"){
      top = temp3;
      dow = temp2;
      rig = 7-temp1;
      ans +=top;
    }else if(sousa =="South"){
      top = 7-temp2;
      dow = temp1;
      rig = temp3;
      ans +=top;
    }else if(sousa =="Right"){
      top = temp1;
      dow = temp3;
      rig = 7-temp2;
      ans += top;
    }else if(sousa =="Left"){
      top = temp1;
      dow = 7-temp3;
      rig = temp2;
      ans += top;
    }
}
  printf("%d\n",ans);
  }
}