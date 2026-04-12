#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
  int a[5][3],m;

  while(1){
    cin >> a[0][0] >> a[0][1];
    if(!a[0][0] && !a[0][1])break;

    for(int i=1;i<5;i++)cin >> a[i][0] >> a[i][1];

    m = 0;
    for(int i=0;i<5;i++){
      a[i][2] = a[i][0] + a[i][1];
      m = max(m,a[i][2]);
    }

    for(int i=0;i<5;i++){
      if(a[i][2] == m)printf("%c %d\n",'A'+i,m);
    }
  }
}