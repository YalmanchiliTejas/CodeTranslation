#include <bits/stdc++.h>

using namespace std;
int main() {

int n=0;
int m=0;
string s;
cin>>s;
  for(int k=0; k<3; k++){
  if(s[k]=='A'){
  	n++;}
  	else{
	  	m++;}}
  	if(n==3||m==3){
  		cout<<"No";
	  }
	  else
	  cout<<"Yes";
	return 0;
}