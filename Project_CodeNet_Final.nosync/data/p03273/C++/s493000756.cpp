#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define rep(n) for(int i=0;i<n;i+=1)
#define fill(c,v) memset(c,v,sizeof(c));
#define prarr(a,n) rep(n) cout<<a[i]<<" \n"[i==n-1]; 
#define sc(a) scanf("%d",&a);
#define scl(a) scanf("%lld",&a);
#define scf(a) ascanf("%f",&a);
#define ff first
#define ss second
#define pu push_back
#define inf 1000000001
#define MOD 1000000007 
#define INF 100000000000001
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    char g[101][101];
    for(int i = 0 ;i< n ; i++)
    {
    	for(int j  = 0 ; j<m ;j++)
    	{
    		cin>>g[i][j];
    	}
    }
    std::vector<int> v,v1;
    rep(n)
    {
    	int j = 0;
    	while(j<m && g[i][j]=='.') j++;
    	if(j==m)
    		v.push_back(i);
    }
    rep(m)
    {
    	int j  = 0;
    	while(j<n && g[j][i]=='.') j++;
    	if(j==n)
    		v1.push_back(i);
    }
    int p1=0,p2=0;
    for(int i = 0 ;i< n ; i++)
    {
    	bool b = 0;
    	p2=0;
		if(p1<v.size() && i==v[p1])
		{
			p1++;
			continue;
		}
    	for(int j  = 0 ; j<m ;j++)
    	{
    		if(p2<v1.size() && j==v1[p2])
    		{
    			p2++;
    			continue;
    			// break;
    		}
    		// b = 1;
    		cout<<g[i][j]<<"";
    	}
    	// if(b)
    		cout<<endl;
    }			
    return 0;

}
