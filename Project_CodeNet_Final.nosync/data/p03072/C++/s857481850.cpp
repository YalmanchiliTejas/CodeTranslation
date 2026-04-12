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
#include<bitset>
#define ld long double
#define ll long long int
#define ull unsigned long long int
#define rep(i,n) for(i=0;i<n;i++)
#define fin(ans) cout<<(ans)<<endl
#define INF INT_MAX
using namespace std;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
const long long LLINF=1LL<<60;
//set<int>::iterator it;



int main(void){ios::sync_with_stdio(false);cin.tie(0);
//////////////////////////////////////////////////////
	
	int i,j,n,ans=0;
	cin>>n;
	int a[n];
	rep(i,n)cin>>a[i];
	for(i=0;i<n;i++){
		bool ch=true;
		for(j=i-1;j>=0;j--){
			if(a[j]>a[i])ch=false;
		}
		if(ch)ans++;
	}
	fin(ans);
	
	
	
	
	
	
	
//////////////////////////////////////////////////////
	return 0;
}
