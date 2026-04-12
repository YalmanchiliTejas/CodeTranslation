#include<bits/stdc++.h> 

using namespace std;

char s[20];

int main(){
	int n,k;
	scanf("%d",&n);
	scanf("%s",s + 1);
	int i;
	scanf("%d",&k);
	for(i = 1;i <= n;i++)if(s[i] != s[k]) s[i] = '*';
	for(i = 1;i <= n;i++)cout<<s[i];
	cout<<endl;
	return 0;
}