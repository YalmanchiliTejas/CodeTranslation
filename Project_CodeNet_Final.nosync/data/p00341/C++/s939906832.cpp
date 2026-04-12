#include<bits/stdc++.h>
using namespace std;





int main(){
  int a[12]={};
  for(int i=0;i<12;i++){
    cin>>a[i];
  }
  int ans=0;
  for(int i=0;i<12;i++){
    int count=0;
    if(a[i]!=0){
      int b=a[i];
      for(int t=i;t<12;t++){
	if(a[t]==b){a[t]=0; count++;}
	if(count==4){ans++; break;}
      }
    }

  }
  cout<<(ans==3? "yes":"no")<<endl;
  

  
  return 0;
}

