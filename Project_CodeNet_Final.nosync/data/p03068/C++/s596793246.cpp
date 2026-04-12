#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;string s;cin>>s;int k;cin>>k;
  	for(auto x:s){
    	if(x!=s[k-1]) cout<<"*";
      	else cout<<x;
    }
}