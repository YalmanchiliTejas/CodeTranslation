#include <bits/stdc++.h>
 
#define rep2(x,fr,to) for(int (x)=(fr);(x)<(to);(x)++)
#define rep(x,to) for(int (x)=0;(x)<(to);(x)++)
#define repr(x,fr,to) for(int (x)=(fr);(x)>=(to);(x)--)
#define all(c) (c).begin(),(c).end()
#define sz(v) (int)(v).size()
 
using namespace std;
typedef long long ll; typedef vector<int> VI; typedef pair<int,int> pii;
const ll mod = 1e9+7;
 
 
 
int main()
{
	
	//cin.tie(0); ios_base::sync_with_stdio(false);
	int n;
	cin >>n;
	vector<VI> ct(n, VI(28));
	rep(i,n){
		string s;
		cin >> s;
		for(auto x: s) ct[i][x-'a']++;
	}
	
	string ans;
	rep(i,26){
		int cmn = 999;
		rep(j,n) cmn=min(cmn, ct[j][i]);
		ans += string(cmn, 'a'+i);
	}
	
	cout << ans <<endl;
	return 0;
}