#include<bits/stdc++.h>
using namespace std;

long long N;
pair<long long, long long > xy[100005];
//            to     ,  cost
vector<pair<long long, long long> >way[100005];

int main(){
	cin >> N;
	//            X      , idx
	vector<pair<long long, long long> >XX;
	//            Y      , idx
	vector<pair<long long, long long> >YY;
	for(long long i = 0; i < N; i++){
		cin >> xy[i].first >> xy[i].second;
		XX.push_back(make_pair(xy[i].first, i));
		YY.push_back(make_pair(xy[i].second, i));
	}

	sort(XX.begin(), XX.end());
	sort(YY.begin(), YY.end());

	for(long long i = 0; i < XX.size() - 1; i++){
		long long from, to, dis;
		from = XX[i].second;
		to = XX[i+1].second;
		dis = min(abs(xy[from].first - xy[to].first), abs(xy[from].second - xy[to].second));
		way[from].push_back(make_pair(to, dis));
		way[to].push_back(make_pair(from, dis));
	}

	for(long long i = 0; i < YY.size() - 1; i++){
		long long from, to, dis;
		from = YY[i].second;
		to = YY[i+1].second;
		dis = min(abs(xy[from].first - xy[to].first), abs(xy[from].second - xy[to].second));
		way[from].push_back(make_pair(to, dis));
		way[to].push_back(make_pair(from, dis));
	}

	long long ans = 0;
	set<long long> done;
	priority_queue<pair<long long, long long>,vector<pair<long long, long long> >, greater<pair<long long, long long> > > Q;

	Q.push(make_pair(0, 0));
	while(!Q.empty()){
		long long node = Q.top().second;
		long long cost = Q.top().first;
		Q.pop();
		if(done.count(node) != 0){
			continue;
		}
		ans += cost;
		done.insert(node);
		for(long long i = 0; i < way[node].size(); i++){
			long long nnode = way[node][i].first;
			long long ncost = way[node][i].second;
			if(done.count(nnode) == 0){
				Q.push(make_pair(ncost, nnode));
			}
		}
	}
	cout << ans << endl;
}
