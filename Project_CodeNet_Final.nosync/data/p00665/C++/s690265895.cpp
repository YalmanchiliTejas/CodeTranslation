#include "bits/stdc++.h"
using namespace std;

struct chara {
	string name;
	int vote;
};
int N, M, K, L;
bool check(const vector<chara>&mcs, const vector<chara>&ocs,int need) {
	if (need == K - ocs.size())return true;
	else {
		chara target = ocs[ocs.size()-1 - (K - need)];
		long long int use = 0;
		for (int i = mcs.size() - 1; i >= int(mcs.size()) - need; --i) {
			chara mc(mcs[i]);
			if (mc.name < target.name) {
				use += max(0, target.vote - mc.vote);
			}
			else {
				use += max(0, target.vote - mc.vote + 1);
			}
		}
		return use <= L;
	}
}

int main() {
	while (1) {
		cin >> N >> M >> K >> L;
		if (!N)break;
		vector<chara>mycharas;
		vector<chara>opcharas;
		{
			map<string, chara>mp;
			for (int i = 0; i < N; ++i) {
				string name; int vote; cin >> name >> vote;
				mp[name] = chara{ name,vote };
			}
			set<string>mynames;
			for (int i = 0; i < M; ++i) {
				string name; cin >> name;
				mynames.emplace(name);

			}
			for (auto m : mp) {
				if (mynames.find(m.first) == mynames.end()) {
					opcharas.push_back(m.second);
				}
				else {
					mycharas.push_back(m.second);
				}
			}
			sort(opcharas.begin(), opcharas.end(), [](const chara&l, const chara&r) {
				return l.vote == r.vote ? l.name > r.name : l.vote < r.vote;
			});
			sort(mycharas.begin(), mycharas.end(), [](const chara&l, const chara&r) {
				return l.vote == r.vote ? l.name > r.name : l.vote < r.vote;
			});
		}
		int amin = max(0,int(K-opcharas.size())), amax = min(int(mycharas.size()),K) + 1;
		while (amin + 1 != amax) {
			int amid = (amin + amax) / 2;
			if (check(mycharas, opcharas, amid)) {
				amin = amid;
			}
			else {
				amax = amid;
			}
		}
		cout << amin << endl;
		
	}
	return 0;
}