#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
#define endl "\n"
#define pii pair<int,int> 
#define ff first
#define ss second
#define mii map<int,int>
#define si set<int>
#define sti stack<int>
#define qi queue<int>
#define vi vector<int>
#define pq priority_queue<int>
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int M=1e9+7;
const int N=1e5+5;

int calc(int x,int y){
	if(x<y) return 0;
	if(x==y) return 1;
	int ans1=1,ans2=1;
	y=min(x-y,y);
	for(int i=x;i>=x-y+1;i--) ans1*=i;
	for(int i=1;i<=y;i++) ans2*=i;
	return(ans1/ans2); 
}

int32_t main(){
	IOS;
	string s; cin>>s;
	int n=s.length();
	int k; cin>>k;
	int ans=0;
	int res=0;
	for(int i=0;i<n;i++){
		char x=s[i];
		for(int j=0;j<(int)(x-'0');j++){
			if(j==0) ans+=calc(n-i-1,k-res)*pow(9,k-res);
			else ans+=calc(n-i-1,k-(res+1))*pow(9,k-res-1);
			//cout<<j<<" "<<ans<<" "<<calc(n-i-1,k-res-1)<<endl;
		}
		if(s[i]!='0') res++;
		if(res==k){
			ans++;
			break;
		}
	}
	cout<<ans<<endl;
}