#include<iostream>
#include<algorithm>
#include<cmath>
#include<map>
#include<stdio.h>
#include<vector>
using namespace std;
#define rep(s,i,n) for(int i=s;i<n;i++)
#define c(n) cout<<n<<endl;
#define ic(n) int n;cin>>n;
#define sc(s) string s;cin>>s;
#define mod 1000000007
#define f first
#define s second
#define int long long
signed main(){
	int a,b,c,x,y;
	cin>>a>>b>>c>>x>>y;
	int ans=1145141919;
	int mon=0;
	rep(0,i,214514){
		if(i%2==1){}
		if(i/2>x){
			if(i/2>y)mon=c*i;
			else mon=b*(y-i/2)+c*i;
		}
		else{
			if(i/2>y)mon=a*(x-i/2)+c*i;
			else mon=a*(x-i/2)+b*(y-i/2)+c*i;
		}
		if(mon<ans)ans=mon;	
	}
	c(ans)
}	