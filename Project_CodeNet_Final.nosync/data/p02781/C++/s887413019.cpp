#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define ll long long



using namespace std;

void file(){
	#ifndef ONLINE_JUDGE
    	freopen("in.txt", "r", stdin);
	#endif
}
int tc;
const int N=2e5+5,M=2e6+5,MOD=1e9+7,OO=1e9;
string a;
int k;
int n;
ll memo[105][5][2];
ll solve(int indx,int curr,bool already){
	if(curr>k)return 0;
	if(indx==n){
		return (curr==k);
	}
	ll &ret = memo[indx][curr][already];
	if(~ret)return ret;
	ret = 0;
	if(already){
		ret = solve(indx+1,curr,1);
		for(int i=1;i<=9;i++){
			ret+=solve(indx+1,curr+1,1);
		}
	}
	else{	
		ret = (a[indx]=='0')?solve(indx+1,curr,0):solve(indx+1,curr,1)+solve(indx+1,curr+1,0);
		for(int i=1;i<(a[indx]-'0');i++)ret+=solve(indx+1,curr+1,1);
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//file();	
 	
 	cin>>a>>k;

 	n = sz(a);

 	memset(memo,-1,sizeof(memo));

 	cout<<solve(0,0,0)<<endl;
}		
