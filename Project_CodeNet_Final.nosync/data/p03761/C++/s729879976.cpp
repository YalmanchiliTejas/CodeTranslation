#include <bits/stdc++.h>
#define itn int
#define REP(i, n) for (int i = 0; i < n; i++)
#define IREP(i, n) for (int i = n - 1; i >= 0; i--)
#define REPEACH(i,k) for(auto& i:k)
#define all(a) a.begin(),a.end()
#define MOD 1000000007
#define int long long
using namespace std;
typedef long long ll;

const ll INF = 1LL << 60;

signed main() {
	int n;
	cin >> n;
	vector<string> s(n);
	map<char,int> m;
	vector<map<char,int>> m2(n);
	REP(i,n){
		cin >> s[i];
		REP(j,s[i].size()){
			m2[i][s[i][j]]++;
		}
		REPEACH(j,m2[i]){
			if(m.find(j.first)==m.end()){
				if(i==0){
					m[j.first]=j.second;
				}
				else{
					continue;
				}
			}
			else{
				m[j.first]=min(j.second,m[j.first]);
			}
		}
	}
	string ans="";
	REPEACH(i,m){
		bool flag=true;
		REP(j,n){
			if(m2[j].find(i.first)==m2[j].end()){
				flag=false;
				break;
			}
		}
		if(flag){
			REP(j,i.second){
			ans+=i.first;
		}
		}
	}
	cout << ans << endl;
}