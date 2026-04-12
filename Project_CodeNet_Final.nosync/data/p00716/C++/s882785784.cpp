#include<bits/stdc++.h>
using namespace std;
int main(){
  int m;
  cin>>m;
  for(int i=0;i<m;i++){
    int money,year,n,max=0;
    cin>>money>>year>>n;
    for(int j=0;j<n;j++){
      int p,tesuu;double per; 
      cin>>p>>per>>tesuu;
      int now=money,tanri=0;
      for(int k=0;k<year;k++){
	if(p==1){
	  now+=(int)(now*per);
	  now-=tesuu;
	}else{
	  tanri+=(int)(now*per);
	  now-=tesuu;
	}

      }
      now+=tanri;
      if(now>max)
	max=now;
    }
    cout<<max<<endl;
  }
  return 0;
}