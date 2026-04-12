#include <bits/stdc++.h>
#define newl "\n"
using namespace std;
using lli = long long int;
using vvint = vector <vector <int>>;
const int mod = 1e9 + 7;

const int N = 2e5 + 1;

void solve(){
	lli n,x,m;
	cin >> n >> x >> m;
	int k = 0;
	map <int,int> s;
	lli x1 = x;
	pair <lli,int> x2 = {x,-1};
//	for(int i = 0;i < m;++i){
//		cout << x1 << newl;
//		x1 = x1 * x1 % m;
//	}
	for(int i = 0;i < m;++i){
		if(s.find(x1) == s.end()){
			s[x1] = i;
		}
		else{
			x2 = {x1,s[x1]};
			break;
		}
		++k;
		x1 = x1 * x1 % m;
	}
	lli summ = 0;
	if(n <= x2.second){
		x1 = x;
		for(int i = 0;i < n;++i){
			summ = summ + x1;
			x1 = x1 * x1 % m;
		}
		cout << summ << newl;
		return;
	}
	n = n - x2.second;
	x1 = x;
	for(int i = 0;i < x2.second;++i){
		summ = summ + x1;
		x1 = x1 * x1 % m;
	}
	x1 = x2.first;
	k = k - x2.second;
	lli summ2 = 0;
	for(int i = 0;i < k;++i){
		summ2 = summ2 + x1;
		x1 = x1 * x1 % m;
	}
	summ = summ + summ2 * (n / k);
	x1 = x2.first;
	for(int i = 0;i < n % k;++i){
		summ = summ + x1;
		x1 = x1 * x1 % m;
	}
	cout << summ << newl;
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(10);
	#ifdef EXECUTE_LOCALLY
		   freopen("in.txt","r",stdin);
	#endif
	int t = 1;
	//cin >> t;
	while(t--) solve();
	#ifdef EXECUTE_LOCALLY
    	cout << setprecision(3) << "program time: " << (double)clock() / CLOCKS_PER_SEC << newl;
	#endif
	return 0;
}
