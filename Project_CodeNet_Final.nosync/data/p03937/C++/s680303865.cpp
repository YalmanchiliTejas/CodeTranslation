#include<bits/stdc++.h>
using namespace std;

const int maxn=10;
int n,m,cnt;
char s[maxn];

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>s;
		for(int j=0;s[j];++j)
			if(s[j]=='#')
				++cnt;
	}
	puts(cnt==n+m-1?"Possible":"Impossible");
	return 0;
}