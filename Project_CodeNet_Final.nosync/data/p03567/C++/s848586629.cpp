#include<bits/stdc++.h>
using namespace std;
char c[100001];
int main(){
	scanf("%s",c);
	int l=strlen(c);
	bool p=false;
	for(int i=0;i<l;i++){
		if(c[i]=='A'&&c[i+1]=='C'){
			p=true;
			break;
		}
	}
	if(p)printf("Yes\n");
	else printf("No\n");
	return 0;
}