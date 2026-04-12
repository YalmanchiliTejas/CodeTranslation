#include<iostream>
using namespace std;
int main(){
  int z,g,max,maxd;
  char a[5]={'A','B','C','D','E'};
  while(cin>>z>>g){
    if(z==0&&g==0) break;
    max = z + g;
    maxd = 0;
    for(int i=1;i<=4;i++){
      cin >> z >> g;
      if(z+g>max){
	max = z+g;
	maxd = i;
      }
    }
    cout << a[maxd] << ' ' << max << endl;
  }
  return 0;
}