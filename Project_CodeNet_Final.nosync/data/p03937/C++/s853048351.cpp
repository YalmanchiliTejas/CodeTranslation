#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)
const int mod=1000000007;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int h,w;cin >> h >> w;
	vector<string> s(h);
	rep(i,h) cin >> s.at(i);
	int cnt=0;
	rep(i,h){
		rep(j,w){
			if(s[i][j]=='#') cnt++;
		}
	}
	if(cnt==h+w-1) cout << "Possible" << endl;
	else cout << "Impossible" << endl;
}
