
/*
ID: Bipin Singh [bipinsingh061]
LANG: C++
TASK: gift1
*/
#include<bits/stdc++.h> 
using namespace std; 
#define deb(x) cout <<"\n"<< (#x) << " = " << (x) << "\n"
#define int long long int

void inputoutput()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
}



bool dfs(int src,int c , bool *vis , vector<int> (&v)[2001] , int col[])
{
	vis[src]=true;
	col[src]=c ;
	// cout<<src<<" ";

	for(auto it : v[src])
	{
		if(!vis[it])
		{
			if(dfs(it,c*-1,vis,v,col)==false)
				return false;
		}
		else
		{
			if(col[src]==col[it])
				return false;
		}
	}
	return true ;
}

int mod=1e9+7 ;


void update(vector<int>& D, int l, int r, int x) 
{ 
    D[l] += x; 
    D[r + 1] -= x; 
}

int32_t main()
{
	inputoutput();


	int n;
	cin>>n;
	int ar[n];
	int pref[n+1];


	for(int i=0 ; i<n ; ++i)
	{
		cin>>ar[i];
	}

	int sum=0;
	for(int i=n-1 ; i>=0 ; --i)
	{
		sum=(sum+ar[i])%mod;
		pref[i]=sum;
	}
	pref[n]=0;

	int ans=0;

	for(int i=0 ; i<n;  ++i)
	{
		ans=(ans+(ar[i]*pref[i+1]) )%mod ;
	}
	cout<<(ans+mod)%mod;


	

	

    



	return 0;
}


