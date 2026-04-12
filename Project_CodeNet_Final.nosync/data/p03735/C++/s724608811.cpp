#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int N;
	while(cin >> N){
		vector< pair<long long, long long> > p(N);
		vector< pair<long long,int> > key(2*N);
		for(int i=0;i<N;i++){
			cin >> p[i].first >> p[i].second;
			if(p[i].first > p[i].second) swap(p[i].first, p[i].second);
			key[2*i] = make_pair(p[i].first, i);
			key[2*i+1] = make_pair(p[i].second, i);
		}
		sort(key.begin(), key.end());
		long long rm = (1LL << 40), rM = 0, bm = (1LL << 40), bM = 0;
		for(int i=0;i<N;i++){
			rm = min(rm, p[i].first);
			rM = max(rM, p[i].first);
			bm = min(bm, p[i].second);
			bM = max(bM, p[i].second);
		}
		long long res = (rM - rm) * (bM - bm);
		if(key[0].second != key.back().second){
			vector<int> use(N, 0);
			int cnt = 0;
			int low = 1, high = 1;
			use[key[1].second] = 1;
			cnt = 1;
			while(true){
				if(cnt < N){
					++high;
					if(high == key.size() -1) break;
					if(!use[key[high].second]) ++cnt;
					use[key[high].second]++;
				} else {
					use[key[low].second]--;
					if(!use[key[low].second]) --cnt;
					++low;
				}
				if(cnt == N){
					res = min(res, (key.back().first - key[0].first) * (key[high].first - key[low].first));
				}
			}
		}
		cout << res << endl;
	}
}

