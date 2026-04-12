#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
  int e[21];
  int ans=0;
  int a[111];
  memset(a,0,sizeof(a));
  for(int i=0;i<12;i++){
    cin >> e[i];
    a[e[i]-1]++;
  }
  
  for(int i=0;i<100;i++){
    if(a[i]>=4){
      ans+=a[i]/4;
    }
  }
  if(ans == 3){
    cout << "yes" << endl;
  }else{
    cout << "no" << endl;
  }
  return 0;
}

