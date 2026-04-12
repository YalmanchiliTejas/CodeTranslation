#include<bits/stdc++.h>
using namespace std;
main(){
  while(1){
    int noon,afternoon,max=0,maxn=-1;
    for(int i=0;i<5;i++){
      cin>>noon>>afternoon;
      if(noon==afternoon&&afternoon==0){
	return 0;
      }
      if(max<noon+afternoon){
	max=noon+afternoon;
	maxn=i;
      }
    }
    char a='A'+maxn;
    cout<<a<<" "<<max<<endl;
  }
}