#include <bits/stdc++.h>
#define fu(i,r,t) for(int i=r;i<=t;i++)
#define fd(i,r,t) for(int i=r;i>=t;i--)
#define ll long long
using namespace std;
char str[5];
int main(){
	cin>>str;
	fu(i,0,1){
		if(str[i]!=str[i+1]){
			cout<<"Yes"<<endl;
			return 0;
		}
	}
	cout<<"No"<<endl;
	return 0;
} 