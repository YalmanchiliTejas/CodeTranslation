#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define xx first
#define yy second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define Max(x) max_element(all(x))
#define Min(x) min_element(all(x))
#define rep(i,n) for(int i=0;i<n;i++)
#define repp(i,k,n) for(int i=k;i<n;i++)
#define reppp(i,k,n,m) for(int i=k;i<n;i+=m)
#define repv(i,n) for(int i=n-1;i=0;i--)
#define vi vector<int> 
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> iv;
typedef pair<int,int> iip;
typedef map<int,int> mii;

int main(){
	int a,b,c;
	cin>>a>>b>>c;
	cout<<(((a*100+b*10+c)%4==0)?"YES":"NO");
	
	return 0;
	}