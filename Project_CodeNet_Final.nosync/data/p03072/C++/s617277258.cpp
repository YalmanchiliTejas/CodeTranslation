#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,ans=0,cur=0,tmp;cin>>n;
  	while(n--){
    	cin>>tmp;
      	if(tmp>=cur){
        	ans++;cur=tmp;
        }
    }
  	cout<<ans;
}