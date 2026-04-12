#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
  	cin>>s;
  	for(int i=0;i+1<s.length();i++){
    	if(s.substr(i,2)=="AC"){
        	cout<<"Yes"; return 0;
        }
    }
  	cout<<"No"; return 0;
}