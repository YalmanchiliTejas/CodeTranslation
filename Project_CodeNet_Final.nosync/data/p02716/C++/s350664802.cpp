#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define mod 1000000007

#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
#define debug4(x,y,z,w) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\t"<<#w<<" :: "<<w<<endl;

const int inf = 1e9;

void mins(int& a,int b){
	a=min(a,b);
}

int main()
{  
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	vector<ll> dp(n),pre(n);

	dp[0]=0;
	dp[1]=max(a[0],a[1]);
	if(n<3){
		cout<<dp[n-1]<<"\n";
		return 0;
	}
	
	dp[2]=max(dp[1],a[2]);
	pre[0]=a[0];
	pre[2]=pre[0]+a[2];
	
	for(int i=3;i<n;i++){
		if(i&1){
			dp[i]=max(a[i]+dp[i-2],a[i-1]+pre[i-3]);
		}
		else{
			dp[i]=max(a[i]+dp[i-2],a[i-1]+dp[i-3]);
			pre[i]=pre[i-2]+a[i];
		}
	}
	
    cout<<dp[n-1]<<"\n";			
}



