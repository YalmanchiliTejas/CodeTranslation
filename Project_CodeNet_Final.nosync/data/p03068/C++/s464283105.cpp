#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int n,k,i,j;
  	string s;
  	cin>>n>>s>>k;
  
  	for(i=0;i<n;i++){
      cout<<(s[i]!=s[k-1]?'*':s[i]);
             
    }

  	
}