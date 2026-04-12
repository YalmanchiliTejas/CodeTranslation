#include<iostream>
#include<algorithm>
#define rep(i,x) for(int i=0;i<x;i++)
using namespace std;

int main(){
	int N;
  cin>>N;
  int H[N];
  rep(i,N){
  	cin>>H[i];
  }
  int ans=1;
  int ma=H[0];
  rep(i,N){
  	if(i>0){
    	if(ma<=H[i]){
        	ma=max(H[i],ma);
          	ans++;
        }
    }
  }
  cout<<ans;
  
  
}