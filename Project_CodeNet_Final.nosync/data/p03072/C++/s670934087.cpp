#include<bits/stdc++.h>
using namespace std;
 
#define rep(i,m,n) for(int i = (m); i < (int)(n); i++)
#define rrep(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define vsort(v) sort(v.begin(), v.end());
#define rvsort(v) sort(v.begin(), v.end(),greater<int>());
#define YES cout<<"YES"<< endl
#define NO cout<<"NO"<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl  
#define yes cout<<"yes"<<endl
#define no cout<<"no"<<endl
#define ret return
#define lb(v,n) lower_bound(v.begin(),v.end(),n)
#define ub(v,n) upper_bound(v.begin(),v.end(),n)
#define mae(v) max_element(v.begin(),v.end())
#define mie(v) min_element(v.begin(),v.end())
#define INF 0x7FFFFFFF
#define mod 1000000007
#define fir first
#define sec second
typedef long long ll;
////////////////////////////////////////////////////////////

int main(){
	int n;
	cin >> n;
	int a[20];
	rep(i,0,n) cin >> a[i];

	int Max = a[0];
	int ans = 1;

	rep(i,1,n){
		if( a[i] >= Max ){
			ans += 1;
		}
		Max = max(Max , a[i] );
	}

	cout << ans << endl;
	ret 0;
}