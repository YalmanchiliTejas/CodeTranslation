#include<bits/stdc++.h>
#define pb push_back
#define pp pop_back()
#define mp make_pair
#define fr first
#define sc second
#define sz size()
#define smin(x,y) ((x)=min((x),(y)))
#define smax(x,y) ((x)=max((x),(y)))
#define all(x) x.begin(),x.end()
#define CS ios_base::sync_with_stdio(false);
#define show(x) cerr << #x << " is " << x <<endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi; 
const int M=2e5+5;
int a[M];
int ans[M];
int32_t main()
{
	int n; cin>>n;
	string s; cin>>s;
	for(int i=0;i<n;i++) if(s[i]=='o') a[i]=0; else a[i]=1;
	for(int mask=0;mask<4;mask++){
		for(int j=0;j<2;j++) ans[j] = (int)((mask)&(1<<j)) ? 1 : 0;
		for(int k=1;k<n-1;k++)
			ans[k+1] = (int)(ans[k]^a[k]^ans[k-1]);
		if( (int)(ans[n-1]^ans[1]^a[0]^ans[0]) | 
			(int)(ans[n-2]^ans[0]^a[n-1]^ans[n-1])
		) continue;
		for(int i=0;i<n;i++) if(ans[i]) cout<<"W"; else cout<<"S"; 
		cout<<endl;
		return 0;
	}
	return cout<<-1<<endl,0;
}
