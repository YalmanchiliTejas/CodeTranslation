#include<bits/stdc++.h>
using namespace std;
int main(){
	int i,a,b;
	char s[3];
	cin>>s;
	a=b=0;
   for(i=0;i<3;i++){
   	if(s[i]=='A')a++;
   	else b++;
   }
   if(a==2&&b==1||(a==1&&b==2)){
   	cout<<"Yes";
   }else {
   	cout<<"No";
   }
} 