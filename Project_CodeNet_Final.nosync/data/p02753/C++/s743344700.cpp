#include<bits/stdc++.h>
using namespace std;
char s[10];
int main(){
	int ans=0;
	for(int i=0;i<3;i++){
		s[i]=getchar();
		if(s[i]=='A')ans++;
		else ans--;
	}
	if(ans==3||ans==-3)cout<<"No";
	else cout<<"Yes";
	return 0;
}

