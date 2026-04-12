#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

#define int int64_t
#define ld long double

const int MOD = 1e9+7;
const int N = 1e6+5;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n,x,m;
	cin>>n>>x>>m;
	int ans[m+2];
	map<int,int> bval;
	ans[1]=x;
	bval[x]=1;
	int cs = -1;
	int ced = -1;
	for(int i=2;i<=m+1;i++) {
		ans[i]=(ans[i-1]*ans[i-1])%m;
		if(bval[ans[i]]) {
			cs = bval[ans[i]];
			ced = i;
		}
		else {
			bval[ans[i]]=i;
		}
	}	
	int pre[m+2];
	pre[0]=0;
	for(int i=1;i<=m+1;i++) {
		pre[i]=pre[i-1]+ans[i];
	}
	if(n<=ced) {
		cout<<pre[n];
	}
	else {
		n-=cs;
		int cl = (ced-cs);
		int ncyc = (n/cl);
		n%=cl;
		int curr = pre[cs-1];
		// cout<<curr<<"\n";
		curr+=(pre[ced-1]-pre[cs-1])*ncyc;
		curr+=pre[cs+n]-pre[cs-1];
		// cout<<curr;
		cout<<curr;
	}

	return 0;
}