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
#include<bits/stdc++.h>
#define ld long double
#define ll long long int
#define ull unsigned long long int
#define rep(i,n) for(i=0;i<n;i++)
#define fin(ans) cout<<(ans)<<endl
#define INF INT_MAX
#define vvi vector<vector<int> >
#define vvc vector<vector<char> >
#define vvs vector<vector<string> >
using namespace std;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
const long long LLINF=1LL<<60;
//set<int>::iterator it;





int main(void){ios::sync_with_stdio(false);cin.tie(0);
//////////////////////////////////////////////////////
	
	
//	int a,b,c;
//	cin>>a>>b>>c;
//	if(b<a)swap(a,b);
//	if(a<=c&&c<=b)fin("Yes");
//	else fin("No");
//	
	
	int n,i,k;
	string s;
	cin>>n>>s>>k;
	char c;
	c=s[k-1];
	rep(i,n){
		if(s[i]!=c)s[i]='*';
	}
	fin(s)<<endl;
	
	
	
	
//////////////////////////////////////////////////////
	return 0;
}





