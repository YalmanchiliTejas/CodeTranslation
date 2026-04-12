#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ll long long
#define lson l,mid,p<<1
#define rson mid+1,r,p<<1|1
#define pii pair<int,int>
using namespace std;
const int inf=1e9+10;
const int mod=1e9+7;
const int maxn=1e5+10;
char s[maxn];
int main(){
	//ios::sync_with_stdio(false);
	//freopen("in","r",stdin);
	cin>>s;
	int n=strlen(s);
	int flag=0;
	for(int i=0;i<n-1;i++){
		if(s[i]=='A'&&s[i+1]=='B') flag=1;
		if(s[i]=='B'&&s[i+1]=='A') flag=1;
	}
	if(flag) puts("Yes");
	else puts("No");
	return 0;
}