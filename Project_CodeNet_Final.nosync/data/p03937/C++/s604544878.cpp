#include <bits/stdc++.h>
#define double long double
#define int long long
#define mii map<int,int>
#define pii pair<int,int>
#define low lower_bound
#define upp upper_bound
#define mod 1000000007 //10^9+7
#define inf 10000000000000000 //10^16
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
	int h,w;
	cin>>h>>w;
	int cnt=0;
	char tab[h][w];
	rep(i,h) {
		rep(j,w) {
			cin>>tab[i][j];
			if(tab[i][j]=='#') cnt++;
		}
	}
	if(cnt==(h+w-1)) cout<<"Possible"<<endl;
	else cout<<"Impossible"<<endl;
}
