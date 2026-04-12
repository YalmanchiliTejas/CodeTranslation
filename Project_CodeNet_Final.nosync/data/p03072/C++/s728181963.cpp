#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int main(void){
	int N,ans=0,max1=0,H1;
  	cin>>N;
  for(int i=0;i<N;i++){
    cin>>H1;
  	if(max1<=H1){ans++;max1=H1;}
  }
  cout<<ans<<endl;
  return 0;
}