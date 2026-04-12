#include <iostream>
#include <string>

using namespace std;

int data[6];

void solve(string);

main(){
  int n;
  while(1){
    cin >> n;
    if(n==0) break;
    for(int i=0;i<6;i++){
      data[i]=i+1;
    }
    int sum=1;
    for(int i=0;i<n;i++){
      string in;
      cin >> in;
      solve(in);
      sum+=data[0];
    }
    cout << sum << endl;
  }
  return 0;
}

void solve(string str){
  int tmp[6];
  for(int i=0;i<6;i++){
    tmp[i]=data[i];
  }
  if(str=="North"){
    data[0]=tmp[1];
    data[1]=tmp[5];
    data[2]=tmp[2];
    data[3]=tmp[3];
    data[4]=tmp[0];
    data[5]=tmp[4];
  }else if(str=="East"){
    data[0]=tmp[3];
    data[1]=tmp[1];
    data[2]=tmp[0];
    data[3]=tmp[5];
    data[4]=tmp[4];
    data[5]=tmp[2];
  }else if(str=="West"){
    data[0]=tmp[2];
    data[1]=tmp[1];
    data[2]=tmp[5];
    data[3]=tmp[0];
    data[4]=tmp[4];
    data[5]=tmp[3];
  }else if(str=="South"){
    data[0]=tmp[4];
    data[1]=tmp[0];
    data[2]=tmp[2];
    data[3]=tmp[3];
    data[4]=tmp[5];
    data[5]=tmp[1];
  }else if(str=="Right"){
    data[0]=tmp[0];
    data[1]=tmp[2];
    data[2]=tmp[4];
    data[3]=tmp[1];
    data[4]=tmp[3];
    data[5]=tmp[5];
  }else if(str=="Left"){
    data[0]=tmp[0];
    data[1]=tmp[3];
    data[2]=tmp[1];
    data[3]=tmp[4];
    data[4]=tmp[2];
    data[5]=tmp[5];
  }
}