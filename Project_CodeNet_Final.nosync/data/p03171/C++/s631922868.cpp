#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mod 1000000007
#define lli long long int
#define mp make_pair
#define mt make_tuple
#define all(x) (x).begin(),(x).end()
#define ve vector<lli>
#define vep vector<pair<lli,lli> >
#define fr(i,n) for(lli i=0;i<(n);i++)
#define F first
#define S second
long long int gcd(long long int a,long long int b)
{
	if(a==0)return b;
	return gcd(b%a,a);
}
int bin(long int a[],long int low,long int high,long d,long day[])
{
	//cout<<low<<" "<<high<<" "<<d<<"\n";
	if(low>high)return -1;
	long mid=(low+high)/2;
	if(a[mid]>(a[low]+d)&&(a[mid-1]<=(a[low]+d)||day[mid-1])&&day[mid]==0)
		return mid;
	else if(a[mid]>(a[low]+d)&&day[mid]==0)
		return bin(a,low,mid-1,d,day);
	else
		return bin(a,mid+1,high,d-a[mid+1]+a[low],day);
}
long long power(long long a,long long b)
{
	//cout<<a<<" "<<b<<"\n";
	if(b==0)return 1;
	if(b%2==0)return (power((a*a),b/2));
	return ((a)*(power((a*a),b/2)));
}
/*int subtree(vector<int>v,int sub[],i,j)
{
	if(sub[i]>0)return sub[i];
	for(auto x:v[i])
	{
		if(x!=j)sub[i]+=subtree(v,sub,x,i);
	}
	return sub[i];
}*/
int edge[100010]={0};
bool cmp(int a,int b)
{
	return edge[a]>edge[b];
}	
bool sortbysecdesc(const pair<int,int> &a, 
                   const pair<int,int> &b) 
{ 
       return a.first>b.first; 
} 
lli re(vector<vector<lli> >v,lli i,lli j,lli n,lli a[])
{
	if(i+j==n)return 0;
	lli b,c;
	//cout<<i<<" "<<j<<"\n";
	if(v[i][n-j-1]>-1)return v[i][n-j-1];
	if(i+1<n)b=v[i+1][n-j-1];
	else b=0;
	if(n-j-2>=0)c=v[i][n-j-2];
	else c=0;
	if(b==-1)b=re(v,i+1,j,n,a);
	if(c==-1)c=re(v,i,j+1,n,a);
	v[i][n-1-j]=max(a[i]-b,a[n-j-1]-c);
	return v[i][n-1-j];
}
int main()
{	
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	int t=1;
	//cin>>t;
	for(int X=1;X<=t;X++)
	{
		//cout<<"Case #"<<X<<": ";
		lli n;
		cin>>n;
		lli a[n],i,j,dp[n][n],k;
		vector<vector<lli> >v(n,vector<lli>(n,-1));
		fr(i,n)cin>>a[i];
		//cout<<re(v,0,0,n,a)<<"\n";
		//cout<<v[n-1][n-1]<<"\n";
		fr(i,n)dp[i][i]=a[i];
		for(k=1;k<n;k++)
		{
			for(i=0;i<n-k;i++)
			{
				j=k+i;
				dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
			}
		}
		cout<<dp[0][n-1]<<"\n";
	}
	return 0;
}