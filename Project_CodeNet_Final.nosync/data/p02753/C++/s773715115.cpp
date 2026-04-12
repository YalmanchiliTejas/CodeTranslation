#include<bits/stdc++.h>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a>b?b:a)
#define lowbit(x) (x&-x)
#define F first
#define S second 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f; 
const int maxn=1e5+10;
int main()
{
	int n,m,q;
	string s;
	cin>>s;
	int a=0,b=0;
	for(int i=0;i<3;i++){
		if(s[i]=='A') a++;
		else b++;
	}
	if(b>0&&a>0) cout<<"Yes";
	else cout<<"No"; 
}
