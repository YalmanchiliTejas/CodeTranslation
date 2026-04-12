#include<algorithm>
#include<bitset>
#include<cmath>
#include<complex>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>

using namespace std;
typedef long long ll;

#define REP(i, n) for(ll i=0;i<(ll)(n);i++)
#define RREP(i, n) for(ll i=(ll)(n-1);i>=0;i--)
#define FOR(i, a, b) for(ll i=(ll)(a), i<=(ll)(b); i++)
#define RFOR(i, a, b) for(ll i=(ll)(a);i>=(ll)(b); i--)
#define ALL(x) (x).begin(),(x).end()
#define SIZE(x) ((ll)(x).size())
#define INF 1000000000000
#define MOD 10000007
#define PB push_back
#define MP make_pair
#define F first
#define S second

ll count(string N, int K)
{
	ll n = N.length();
	string com="0";
	if(n==1 and N==com){
		return 0;
	}
	if(N.substr(0, 1)==com){
		return count(N.substr(1, n-1), K);
	}
	string n10 = string(n-1, '9');
	string tmp = N.substr(0, 1);
	ll nmax=stoi(tmp);
	switch(K){
		case 1:
			if(n==1){
				return stoi(N);
			}
			else{
				return (ll)(nmax+count(n10, 1));
			}
			break;
		case 2:
			if(n==1){
				return 0;
			}
			else if(n==2){
				tmp = N.substr(1, 1);
				return (ll)(nmax-1)*9+stoi(tmp);
			}else{
				return count(n10, 2)+(nmax-1)*count(n10, 1)+count(N.substr(1, n-1), 1);
			}
			break;
		case 3:
			if(n==1){
				return 0;
			}else if(n==2){
				return 0;
			}else if(n==3){
				return count(to_string(99), 2)*(nmax-1)+count(N.substr(1, 2), 2);
			}else{
				return count(n10, 3)+(nmax-1)*count(n10, 2)+count(N.substr(1, n-1), 2);
			}
			break;
	}
}

signed main()
{
	ll K;
	string N;
	cin >> N;
	cin >> K;
	cout << count(N, K);
	cout << endl;
}
