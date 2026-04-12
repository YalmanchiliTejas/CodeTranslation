#include <algorithm>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <list>
#define INF 10000000000ll
#define MOD 1000000007ll
#define EPS 1e-10
#define REP(i,m) for(long long i=0; i<m; i++)
#define FOR(i,n,m) for(long long i=n; i<m; i++)
#define DUMP(a) for(long long dump=0; dump<(ll)a.size(); dump++) { cout<<a[dump]; if(dump!=(ll)a.size()-1) cout<<" "; else cout<<endl; }
#define ALL(v) v.begin(),v.end()
#define pb push_back
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
typedef long double ld;
using namespace std;

int main(){
	int n;
	cin >> n;
	int o[n][26] = { };
	REP(i, n){
		string s;
		cin >> s;
		REP(j, s.size()) o[i][(int)(s[j]-'a')]++;
	}
	REP(i, 26){
		int m = 1000;
		REP(j, n){
			m = min(m, o[j][i]);
		}
		REP(j, m) cout << (char)(i + 'a');
	}
	cout << endl;
	return 0;
}
