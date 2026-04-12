#include <bits/stdc++.h>

using namespace std;

const int N=1e6+3;

const double eps=0.000000001;

#define pb push_back
#define all(x) (x).begin(),(x).end()
typedef long long ll;

const int dx[]={1,-1,0,0},
		  dy[]={0,0,1,-1};

const int inf=1e9,mod=1e9+7;

int n,m,a[N],b[N],k,q,u,v,x,y,tc,c,l,r,ans,cnt[100005];

char s[N];

void IO(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("test.txt","r",stdin);
	#endif
}

int main(){
	//IO();
	scanf("%s",s);
	char c=s[0];
	for(int i=1;s[i];i++)
		if (s[i]!=c)
			return !printf("Yes\n");
	printf("No\n");	
}
