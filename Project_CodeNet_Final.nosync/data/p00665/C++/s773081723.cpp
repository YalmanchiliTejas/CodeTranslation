#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

int main(){
	int N, M, K, L;
	while(cin >> N >> M >> K >> L, N){
		vector< pair<int, string> > vp;
		for(int i=0;i<N;i++){
			string str; int d;
			cin >> str >> d;
			vp.push_back(make_pair(-d, str));
		}
		sort(vp.begin(), vp.end());
		set<string> S;
		for(int i=0;i<M;i++){
			string str;
			cin >> str;
			S.insert(str);
		}
		vector<int> rank;
		for(int i=0;i<N;i++)
			if(S.count(vp[i].second)) rank.push_back(i);
		int l = 0, h = min(M, K)+1;
		while(h-l>1){
			int mid = (l+h)/2;
			int lest = mid;
			int against = K-mid;
			long long vote = 0;
			for(int i=0;i<mid;i++){
				if(rank[i] <= against) against++;
				else {
					vote += -vp[against].first + vp[rank[i]].first + (vp[against].second < vp[rank[i]].second);
				}
			}
			if(vote > L) h = mid;
			else         l = mid;
		}
		cout << l << endl;
	}
}