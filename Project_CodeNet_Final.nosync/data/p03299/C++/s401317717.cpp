//teja349
#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip> 
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val

using namespace std;
#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
#define ll long long
#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
ll perfect[123],dp[123][123],h1[123],h[123],last[123],cur[123];
//std::ios::sync_with_stdio(false);   
ll powe(ll val){
	ll ans=1;
	ll a=2;
	while(val>0){
		if(val%2){
			ans*=a;
			ans%=mod;
		}
		a*=a;
		a%=mod;
		val/=2;
	}
	return ans;
}
ll func(ll n){
	 // cout<<n<<endl;
    ll i,j;
    map<ll,ll> mapi;
    map<ll,ll>::iterator it;
    mapi.clear();
    rep(i,n){
    	//cin>>>h[i];
    	mapi[h[i]]=0;
    }
    ll counter=0;
    ll previ=0;
    for(it=mapi.begin();it!=mapi.end();it++){
    	last[counter]=previ;
    	cur[counter]=it->ff;
    	previ=it->ff;
    	it->ss=counter++;
    }
    rep(i,mapi[h[0]]+1){
    	if(i==0){
    		dp[0][i]=(powe(cur[i]-last[i])-2)*powe(h[0]-cur[i]);
    		
    	}
    	else{
    		dp[0][i]=(powe(cur[i]-last[i])-1)*powe(h[0]-cur[i]);
    		dp[0][i]%=mod;
    		dp[0][i]*=2;

    	}
    	//cout<<dp[0][i]<<endl;
    	dp[0][i]%=mod;
    	dp[0][i]+=mod;
    	dp[0][i]%=mod;

    }
    perfect[0]=2;
    f(i,1,n){

    	rep(j,min(mapi[h[i]],mapi[h[i-1]])+1){
    		dp[i][j]=dp[i-1][j];
    		if(h[i-1]<h[i]){
    			dp[i][j]*=powe(h[i]-h[i-1]);
    			dp[i][j]%=mod;
    		}

    	}
    	perfect[i]=perfect[i-1]*2;
    	perfect[i]%=mod;
    	f(j,mapi[h[i]]+1,mapi[h[i-1]]+1){
    		perfect[i]+=dp[i-1][j]*2;
    		perfect[i]%=mod;
    	}
    	f(j,mapi[h[i-1]]+1,mapi[h[i]]+1){
    		//cout<<last[j]<<endl;
    		dp[i][j] = (powe(cur[j]-last[j])-1)*powe(h[i]-cur[j]);
    		dp[i][j]%=mod;
    		dp[i][j]*=perfect[i];
    		dp[i][j]%=mod;
    	}



    }
    ll ans=0;
    rep(j,mapi[h[n-1]]+1){
    	//cout<<dp[n-1][j]<<endl;
    	ans+=dp[n-1][j];
    	ans%=mod;
    }
    //cout<<perfect[n-1]<<endl;
    ans+=perfect[n-1];
    ans%=mod;
    return ans;




    return 0;  
    
}
int main(){
	ll n;
	cin>>n;
	ll i,j;
	rep(i,n){
		cin>>h1[i];
	}
	//return 0;
	ll ans=1;
	j=0;
	rep(i,n){
		if(h1[i]==1){
			ans*=2;
			ans%=mod;
			if(j!=0){
				ans*=func(j);
				ans%=mod;
			}
			j=0;

		}
		else{
			h[j++]=h1[i];
		}
	}
	if(j!=0){
		ans*=func(j);
		ans%=mod;
	}
	ans+=mod;
	ans%=mod;
	cout<<ans<<endl;
	return 0;
}
