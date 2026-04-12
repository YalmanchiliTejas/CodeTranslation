#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <bitset>
#include <climits>
using namespace std;

const long long INF = LLONG_MAX / 4;

int main(){
	int n, m, w, t;
	cin >> n >> m >> w >> t;

	map<string, int> name;

	vector<int> v(m), sell(m); // ツ重ツつウツ、ツ氾個板可ソツ格
	for(int i=0; i<m; ++i){
		string s;
		cin >> s >> v[i] >> sell[i];
		name[s] = i;
	}

	vector<int> x(n), y(n);
	vector<vector<long long> > buy(n, vector<long long>(m, INF)); // ツ仕ツ禿シツづェツ値
	for(int i=0; i<n; ++i){
		int l;
		cin >> l >> x[i] >> y[i];
		for(int j=0; j<l; ++j){
			string s;
			int a;
			cin >> s >> a;
			buy[i][name[s]] = a;
		}
	}

	vector<int> order(n);
	for(int i=0; i<n; ++i)
		order[i] = i;

	vector<long long> minTime(1<<n, INF);
	vector<vector<long long> > minBuy(1<<n, vector<long long>(m, INF));
	do{
		bitset<7> bs;
		long long len = 0;
		int y0 = 0;
		int x0 = 0;
		for(int j=0; j<n; ++j){
			int curr = order[j];
			bs[curr] = true;
			for(int k=0; k<m; ++k)
				minBuy[bs.to_ulong()][k] = min(minBuy[bs.to_ulong()][k], buy[curr][k]);
			len += abs(y0 - y[curr]) + abs(x0 - x[curr]);
			minTime[bs.to_ulong()] = min(minTime[bs.to_ulong()], len + abs(y[curr]) + abs(x[curr]));
			y0 = y[curr];
			x0 = x[curr];
		}
	}while(next_permutation(order.begin(), order.end()));

	vector<long long> maxMoney(1<<n, 0); // ツ嘉アツづゥツ店ツづ可妥篠つオツづづ個催妥・ツ猟伉益
	for(int i=0; i<(1<<n); ++i){
		vector<long long> maxMoneyTmp(w+1, 0); // ツ重ツづ敖づ可妥篠つオツづづ個催妥・ツ猟伉益
		for(int j=1; j<=w; ++j){
			maxMoneyTmp[j] = maxMoneyTmp[j-1];
			for(int k=0; k<m; ++k){
				if(j - v[k] >= 0)
					maxMoneyTmp[j] = max(maxMoneyTmp[j], maxMoneyTmp[j-v[k]] + sell[k] - minBuy[i][k]);
			}
		}
		maxMoney[i] = maxMoneyTmp[w];
	}

	vector<long long> ret(t+1, 0); // ツ篠楪甘板づ可妥篠つオツづづ個催妥・ツ猟伉益
	for(int i=1; i<=t; ++i){
		ret[i] = ret[i-1];
		for(int j=0; j<(1<<n); ++j){
			if(i - minTime[j] >= 0)
				ret[i] = max(ret[i], ret[i-minTime[j]] + maxMoney[j]);
		}
	}

	cout << ret[t] << endl;

    return 0;
}