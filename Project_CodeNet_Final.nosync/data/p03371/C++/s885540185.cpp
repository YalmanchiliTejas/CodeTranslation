#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<list>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<cctype>
#include<climits>
#define ld long double
#define ll long long int
#define ull unsigned long long int
#define rep(i,n) for(i=0;i<n;i++)
#define fin(ans) cout<<(ans)<<endl
#define INF INT_MAX;
using namespace std;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
const long long LLINF=1LL<<60;
//set<int>::iterator it;



int main(void){ios::sync_with_stdio(false);cin.tie(0);
//////////////////////////////////////////////////////
	
	ll a,b,ab=0,A,B,C,t;
	cin>>A>>B>>C>>a>>b;
	if(A+B>=C*2){
		ab+=min(a,b)*2;
		t=min(a,b);
		a-=t;
		b-=t;
	}
//	cout<<a<<" "<<b<<" "<<ab<<endl;
	ll ans=a*A+b*B+ab*C;
//	cout<<ans<<endl;
	if(max(a,b)*2*C+ab*C<ans){
		ans=max(a,b)*2*C+ab*C;
	}
	cout<<ans<<endl;
	
	
	
//////////////////////////////////////////////////////
	return 0;
}
