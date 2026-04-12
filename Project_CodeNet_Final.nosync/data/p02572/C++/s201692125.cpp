#include <bits/stdc++.h>
using namespace std;
#define M (int)1e9
#define pi 3.1415926536
#define all(a) a.begin(),a.end()
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define flp(i,x,y) for(long long int i=x;i<y;i++)
#define ll long long int 
#define MOD (long long int)(1000000007)
#define pb push_back
#define lop(i,n) for(ll i=0;i<n;i++)
#define lop1(i,n) for(ll i=1;i<=n;i++)
#define lopr(i,n) for(ll i=n-1;i>=0;i--)
#define fr         first
#define sc         second
#define pii        pair<int,int>
#define len(s)     s.length()
#define meme(a,val) memset(a,val,sizeof(a));
template<typename T,typename T1>T maxn(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T minn(T &a,T1 b){if(b<a)a=b;return a;}
	vector <int> SieveOfEratosthenes(int n) 
	{ 
	    vector<int> ans;
	    bool prime[n+1]; 
	    memset(prime, true, sizeof(prime)); 
	  
	    for (int p=2; p*p<=n; p++) 
	    if (prime[p] == true) 
	    for (int i=p*p; i<=n; i += p) 
	    prime[i] = false; 
	        
	  	for (int p=2; p<=n; p++) 
	    if (prime[p]) 
	    ans.push_back(p);
		return ans;
	}
	 
	vector <int> fib(int n)
	{
		vector<int> ans;
		int x=0,y=1,l=1;
		ans.push_back(x);
		ans.push_back(y);
		while(l<n)
		{
			l=x+y;
			x=y;y=l;
			ans.push_back(l);
		}
		return ans;
	}
	 
	bool isPrime(ll n) 
	{ 
		if (n <= 1) return false; 
		if (n <= 3) return true; 
	 
		if (n%2 == 0 || n%3 == 0) return false; 
	 
		for (ll i=5; i*i<=n; i=i+6) 
			if (n%i == 0 || n%(i+2) == 0) 
			return false; 
	 
		return true; 
	} 
	 
	 
	long long power(int n,int k)
	{
		if(k==0)	return 1;
		else return (n*power(n,k-1)%1000000007);
	}
	 
	long long nCr(int n,int r)
	{
		if(n==r)	return 1;
		else if (r==0)	return 1;
		else return ((nCr(n-1,r-1)+nCr(n-1,r))%998244353);
	}

	int sdigit(int x)
	{
		int ans=0;
		while(x)
		{
			ans+=x%10;
			x/=10;
		}
		return ans;
	}
	 
	long long lcm(int a,int b)
	{
		return ((long long)a*(long long)b)/__gcd(a,b);
	}
	 
	 
	 pair<int,int> subArraySum(int arr[], int n, int sum) 
	{ 
	    int curr_sum = arr[0], start = 0, i; 
	  
	    for (i = 1; i <= n; i++) 
	    { 
	        while (curr_sum > sum && start < i - 1) 
	        { 
	            curr_sum = curr_sum - arr[start]; 
	            start++; 
	        } 
	  
	        
	        if (curr_sum == sum) 
	        {  
	            //cout << "Sum found between indexes " 
	              //   << start << " and " << i - 1; 
	            return make_pair(start,i-1); 
	        } 
	  
	        if (i < n) 
	        curr_sum = curr_sum + arr[i]; 
	    } 
	  
	    return make_pair(-1,-1); 
	} 

	int bs(int a[],int b,int l,int r)
	{
		int mid=(l+r)/2;
		if(l>r)	return -1;
		if(a[mid]==b||l==r)	return mid;
		if(a[mid]>b)	return bs(a,b,l,mid-1);
		else return bs(a,b,mid+1,r);
	}

	int divideandconquerbc(int a[],int l,int r)
	{
		if(l>=r)	return 0;
		int mid=(l+r)/2,ans=0;
		ans+=divideandconquerbc(a,l,mid);
		ans+=divideandconquerbc(a,mid+1,r);
		int x=r-l+1,y=mid-l+1;
		int c[x];
		int i=0,j=0;
		for(int k=0;k<x;k++)
		{
			if((a[l+i]<=a[mid+1+j]&&i<y)||j>=x-y)	{c[k]=a[l+i];i++;}
			else {c[k]=a[mid+1+j];j++;ans+=y-i;}
			//cout<<c[k]<<" "<<ans<<endl;
			
		}
		for(int k=l;k<=r;k++)
			a[k]=c[k-l];
	    return ans;
	}

	void explore(bool a[],vector<vector <int> >adj,int u)
	{
		if(a[u-1])	return;
		else	a[u-1]=true;
		for(int i=0;i<adj[u-1].size();i++)
		{
			explore(a,adj,adj[u-1][i]+1);
		}
	}
	long long  gcd(int a,int b)
	{
	    if (b==0) return a;
	    return gcd(b,a%b);
	}
	 
	double startTime;
	double getCurrentTime() {
		return ((double)clock() - startTime) / CLOCKS_PER_SEC;
	}
	/*int dfs(int u,int f)
	{
		depth[u]=depth[f]+1;size[u]=1;
		for (int i=0;i<conj[u].size();++i)
		{
			if ((v=conj[u][i])==f)continue;
			size[u]+=dfs(v,u);
		}
		det[u]=size[u]-depth[u];return size[u];*/
void out()
{
	
 
}	
/*int mex(int r[])
{
	int n=sizeof(r)/sizeof(r[0]);
	int b[n+1]={};
	int st=0;
	flp(i,0,n)
	{
		b[a[i]]=1;
		while(b[st]==1)
			st++;
	}
	return st;

}*/
/*ll modInverse(ll n, ll p) 
{ 
    return power(n, p-2, p); 
}*/ 
bool check(int x1,int y1,int x2,int y2,int x3,int y3)
{
	int d1=pow(abs(x1-x2),2)+pow(abs(y1-y2),2);
	int d2=pow(abs(x2-x3),2)+pow(abs(y2-y3),2);
	int d3=pow(abs(x1-x3),2)+pow(abs(y1-y3),2);
	if(d3==(d1+d2)||d2==(d1+d3)||d1==(d2+d3)) return true;
	else return false;
}
	int main()
	{
		//#ifndef ONLINE_JUDGE
		//freopen("input.txt","r",stdin);
		//freopen("ou.txt","w",stdout);
		//#endif
		fastio 
		 ll T,i,n,j;
	//long	double ar;
	T=1;
			
		//cin>>T;
		bool res=false;
	//	ctr=1;
		ll cnt=1;
		while(T--)
		{
			res=false;
			string t,s,str;
			bool res2=false;
			cin>>n;
			ll a[n],p[n];
			flp(i,0,n) cin>>a[i];
			p[0]=a[0];
			flp(i,1,n) p[i]=p[i-1]+a[i];
			ll sum=0;
			flp(i,0,n)
			{
				sum+=((p[n-1]-p[i])%MOD*a[i]%MOD)%MOD;
			}
			sum=sum%MOD;
			cout<<sum<<"\n";
					
			






						

						


			

			
			


			

			



					



			
			
			
				
							

				

		}
		return 0;
	}
	//YASH VERMA #Destructive_Yash