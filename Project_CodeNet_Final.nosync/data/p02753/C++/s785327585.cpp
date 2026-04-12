#include"bits/stdc++.h"
#include<cstring>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
	string s;
	int a=0,b=0;
	int ans=0;
	cin>>s;
	rep(i,3){
		if(s[i]=='A')a++;
		if(s[i]=='B')b++;
	}
	if(a!=0&&b!=0)ans=1;
	if(a!=0&&b==0)ans=0;
	if(a==0&&b!=0)ans=0;

	if(ans==1)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;

	return 0;

}