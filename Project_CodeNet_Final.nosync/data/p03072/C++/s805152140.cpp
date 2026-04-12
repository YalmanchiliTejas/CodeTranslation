#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define INF 1e9+7
#define cases int t;cin>>t;while(t--)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define per(i,a,b) for(ll i=a;i>=b;i--)
#define ff first
#define ss second

#define test4(x,y,z,a) cout<<"x is "<<x<<"		y is "<<y<<"		z is "<<z<<"		a is "<<a<<endl;
#define test3(x,y,z) cout<<"x is "<<x<<"		y is "<<y<<"		z is "<<z<<endl;
#define test2(x,y) cout<<"x is "<<x<<"		y is "<<y<<endl;
#define test1(x) cout<<"x is "<<x<<endl;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	ll n;
	cin>>n;
	ll h[n];
	rep(i,0,n){
		cin>>h[i];
	}
	ll flag,cnt=0;
	rep(i,0,n){
		flag=0;
		rep(j,0,i){
			if(h[i]<h[j]){
				flag=1;
				break;
			}
		}
		if(!flag){
			cnt++;
		}
	}
	cout<<cnt;
	
	
	return 0;
}