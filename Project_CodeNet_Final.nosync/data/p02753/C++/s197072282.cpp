#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=1e6+5;

const ll mod=1e9+7;

char s[maxn];

int main(){
	scanf("%s",s+1);
	int flg=0,flg2=0;
	for(int i=1;i<=3;i++){
		if(s[i]=='A') flg=1;
		else flg2=1;
	}
	if(flg&&flg2) printf("Yes");
	else printf("No");
	return 0;
}