#include <bits/stdc++.h>
#define double long double
#define int long long
#define mii map<int,int>
#define low lower_bound
#define upp upper_bound
#define inf 1000000007 //10^9+7
#define rep(i,n) for(int i=0;i<n;i++)
#define all(vec) vec.begin(),vec.end()
#define vsort(vec) sort(all(vec))
#define vrever(vec) reverse(all(vec));
#define vunsort(vec) vsort(vec); vrever(vec);
#define bisea binary_search
#define cend cout<<endl;
#define F first
#define S second
using namespace std;
signed main() {
	int n;
	cin>>n;
	int a=inf;
	int cnt[n][26];
	string y="abcdefghijklmnopqrstuvwxyz";
	rep(i,n) rep(j,26) cnt[i][j]=0;
	rep(i,n) {
		string s;
		cin>>s;
		int m=s.size();
		rep(j,m) {
			cnt[i][s[j]-'a']++;
		}
	}
	rep(i,26) {
		rep(j,n) {
			a=min(a,cnt[j][i]);
		}
		rep(j,a) cout<<y[i];
		a=inf;
	}
	cend;
}
