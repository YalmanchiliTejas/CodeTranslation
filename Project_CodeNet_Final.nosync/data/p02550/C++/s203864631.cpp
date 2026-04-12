#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7



int main(){
	ll N, X, M;
	cin >> N >> X >> M;

	//idx, sum
	vector<pair<ll, ll> > memo(M+1, make_pair(-1, -1));


	ll idx = 0;
	ll cur = X;
	ll cursum = X%M;
	ll checkloop = true;
	while(idx < N - 1) {
		//cout << idx << " " << cur << " " << cursum << endl;
		if(checkloop && memo[cur].first != -1) {
			//ワープ
			//cout << "wapu" << endl;
			checkloop = false;
			ll lastidx = memo[cur].first;
			ll interval = idx - lastidx;
			ll addnum = cursum - memo[cur].second;
			ll loopnum = max(((N - idx) / interval - 1), 0ll);

			//cout << "interval = " << interval << endl;
			//cout << "addnum = " << addnum << endl;
			//cout << "loopnum = " << loopnum << endl;
			
			idx += loopnum * interval;
			cursum += loopnum * addnum;

			continue;
		}
		memo[cur].first = idx;
		memo[cur].second = cursum;


		cur = (cur * cur) % M;
		cursum += cur;

		idx++;
	}

	cout << cursum << endl;



}
