#include <bits/stdc++.h>
#define int long long
#define moder 1234567
#define inf 1000000000000000000
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define P pair<int,int>
#define all(v) v.begin(),v.end()
#define prique(T) priority_queue<T,vector<T>,greater<T>>
#define vecunique(vec) sort(vec.begin(), vec.end());decltype(vec)::iterator result = std::unique(vec.begin(), vec.end());vec.erase(result, vec.end())
using namespace std;
int h,w;
char c[10][10];
int cnt;
signed main() {
	cin>>h>>w;
	rep(i,h)rep(j,w){
		cin>>c[i][j];
		if(c[i][j]=='#')cnt++;
	}
	if(cnt==h+w-1)cout<<"Possible"<<endl;
	else cout<<"Impossible"<<endl;
}
