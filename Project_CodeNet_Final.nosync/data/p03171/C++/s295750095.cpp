#include<bits/stdc++.h>
    using namespace std;
  #define int long long int
    #define endl "\n"
    #define MOD 1000000007
    #define mod 1000000007
    #define M 1000000007
    
    #define pb push_back
    #define take(a,b,c) for(int b=0;b<c;b++) cin>>a[b]
  //  #define mp make_pair
  #define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);  
  #define mx 400005
  #define fiint(a,b) memset(a,b,sizeof(a))  
  #define bitcount __builtin_popcount
  #define fori(i,a,b) for(int i=a;i<b;i++)
  #define ford(i,a,b) for(int i=a;i>=b;i--)
  #define debug(x) cout<<x<<endl;
  #define cases(t) int t; cin>>t; while(t--)
  #define inf1 INT_MAX
  #define all(a) a.begin(),a.end()
  #define vec vector<int>
  #define pii pair<int,int>
  #define plii pair<int,int>
  #define pint pair<int,int>
  #define ff first
  #define ss second
  #define lb lower_bound
  #define ub upper_bound
  #define bs binary_search
  #define sz(x) (int)x.size()
#define PI                    3.14159265359

bool prime[10000001];

void sieveFunction(int maxLimit){
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1]=false;
    for(int i=2; maxLimit >= i ; i++){
        if(prime[i]){
            for(int j=2*i ; maxLimit >= j ; j+=i)
                prime[j]=false;
        }
    }
}



signed  main() 
{ 
	int n,k;cin>>n;
	vec v(n+1);
	fori(i,1,n+1) cin>>v[i];
	int dp[n+2][n+2];
	fori(i,0,n+2)
		fori(j,0,n+2)
			dp[i][j]=0;
	int x=0,y=0;
	int turn = 0;
	

	ford(l,n,1)
		fori(r,l,n+1)
			if(l==r)
				dp[l][r] = v[l];
			else
			dp[l][r] = max ( v[r] - dp[l][r-1]  ,v[l] -  dp[l+1][r]  );   
		
		cout<<dp[1][n]<<endl;



}

 
