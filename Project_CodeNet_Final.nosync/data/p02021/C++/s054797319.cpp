#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define eps LDBL_EPSILON
#define moder 1000000007
#define int long long
#define ll long long
#define INF ((ll)1<<31)-1
#define P std::pair<int,int>
#define prique priority_queue<int,vector<int>,greater<int>>
using namespace std;
int gcd(int a,int b){
	if(!a)return b;
	return gcd(b%a,a);
}
int lcm(int a,int b){
	return a/gcd(a,b)*b;
}
int n,a[110];
signed main(){
	cin>>n;
	rep(i,n)cin>>a[i];
	rep(i,101){
		int st=0;
		rep(j,n){
			st+=a[j];
			if(st<i){
				cout<<i-1<<endl;
				return 0;
			}
			st-=i;
		}
	}
    return 0;
}
