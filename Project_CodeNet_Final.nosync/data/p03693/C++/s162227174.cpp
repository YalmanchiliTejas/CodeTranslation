#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c;cin>>a>>b>>c;
  	int res = a*100+b*10+c;
  	if(res%4) cout<<"NO";
  	else cout<<"YES";
}