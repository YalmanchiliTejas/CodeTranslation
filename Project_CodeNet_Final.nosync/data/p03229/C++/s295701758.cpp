#include <bits/stdc++.h>
#define f(i,n) for(int i=0;i<(n);i++)
#define P pair<int,int>
#define int long long
#define LONG LLONG_MAX/3;
#define INT INT_MAX/3;
#define mod 1000000007
typedef long long ll;
using namespace std;

int b[100000];

int mypow(int a,int b){
	if(b==0)return 1;
	if(b%2)return mypow(a,b-1)*a%mod;
	return mypow(a,b/2)*mypow(a,b/2)%mod;
}
int kaijo(int n){
	int ans=1;
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=mod;
	}
	return ans;
}
int gcd(int a,int b){
	if(b==0) return a;
	return gcd(b,a%b);
}
int lcm(int a,int b){
	return a/gcd(a,b)*b;
}

signed main(){
	int a;
	cin>>a;
	f(i,a){
		cin>>b[i];
	}
	sort(b,b+a);
	int ans=0,ansans=0;
	int y;
	y=b[(a-1)/2];
	f(i,a-1){
		if(i%2==0){
			ans+=abs(y-b[a-1-i/2]);
			y=b[a-1-i/2];
		}
		else{
			ans+=abs(y-b[i/2]);
			y=b[i/2];
		}
	}
	ansans=ans;
	ans=0;
	y=b[a/2];
	f(i,a-1){
		if(i%2==1){
			ans+=abs(y-b[a-1-i/2]);
			y=b[a-1-i/2];
		}
		else{
			ans+=abs(y-b[i/2]);
			y=b[i/2];
		}
	}
	ansans=max(ansans,ans);
	cout<<ansans<<endl;
	return 0;
}
