#include<bits/stdc++.h>
using namespace std;

char s[100005],ans[100005];
int n;

int main(){
	scanf("%d%s",&n,&s);
	char tmp;
	bool f=false;
	for(int i=0;i<4;i++){
		if(i/2==0) ans[0]='S';
		else ans[0]='W';
		if(i%2==0) ans[1]='S';
		else ans[1]='W';
		for(int j=2;j<n;j++){
			tmp=s[j-1];
			if(ans[j-1]=='W') tmp='o'+'x'-tmp;
			if(tmp=='o') ans[j]=ans[j-2];
			else ans[j]='S'+'W'-ans[j-2];
		}
		if(ans[n-2]==ans[0]) tmp='o';
		else tmp='x';
		if(ans[n-1]=='W') tmp='o'+'x'-tmp;
		if(s[n-1]!=tmp) continue;
		if(ans[n-1]==ans[1]) tmp='o';
		else tmp='x';
		if(ans[0]=='W') tmp='o'+'x'-tmp;
		if(s[0]!=tmp) continue;
		f=true;
		break;
	}
	if(!f) printf("-1\n");
	else printf("%s\n",ans);
	return 0;
}