#include<iostream>
#include<iomanip>
#include<map>
#include<set>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<cstring>
#include<sstream>
using namespace std;
 
#define P(p) cout<<(p)<<endl
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


////////////////////////////////////////////////////////////

int main(){
	int a,b,c,x,y;
	cin >> a >> b >> c >> x >> y;
	
	if(x < y ){
		swap(x,y);
		swap(a,b);
	}
	
	long ans = 0;
	if( a + b > c * 2  ){
		ans += c*y*2;
		
		ans += min((x-y)*a , (x-y)*c*2 );

	}
	else{
		ans += a*x + b*y;	
	}
	
	P(ans);

	ret 0;
}