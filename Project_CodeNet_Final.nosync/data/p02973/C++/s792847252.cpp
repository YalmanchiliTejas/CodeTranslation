#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define INTINF 1999999999
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define MODA 1000000007 
 
int main() {
	int ans = 0;
	int tmp;
	int n;
	cin >> n;
	vector<int> a;
	REP(i, n){
		cin >> tmp;
		auto it = upper_bound(a.begin(), a.end(), -tmp);
		if(it == a.end()){
			ans++;
			a.push_back(-tmp);
		}
		else {
			*it = -tmp;
		}
	}
	cout << ans << endl;
}