#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pie 3.141592653589793238462643383279
#define mod 1000000007
#define INF LLONG_MAX/5
#define all(v) v.begin(),v.end()
#define P pair<int,int>
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
int mypow(int a,int b,int c){
	if(b==0)return 1;
	if(b%2)return mypow(a,b-1,c)*a%c;
	int z=mypow(a,b/2,c);
	return z*z%c;
}
int gcd(int a,int b){
	if(b==0)return a;
	return gcd(b,a%b);
}
int lcm(int a,int b){
	return a/gcd(a,b)*b;
}
int x[10][10];
signed main(){
	int a,b;
	cin>>a>>b;
	if(a==b)puts("Yes");
	else puts("No");
}
