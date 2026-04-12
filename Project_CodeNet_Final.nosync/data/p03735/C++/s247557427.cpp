#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i, s, n) for (int i = (s); i < (n); i++)
#define RFOR(i, s, n) for (int i = (n) - 1; i >= (s); i--)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, 0, n)
#define ALL(a) a.begin(), a.end()
const long long MOD = 1e9 + 7, INF = 1e18;
template<class T>inline bool CHMAX(T&a,T b){if(a<b){a=b;return true;}return false;}
template<class T>inline bool CHMIN(T&a,T b){if(a>b){a=b;return true;}return false;}


signed main(){
	int N;
	cin >> N;
	vector<pair<int,int>>v;
	REP(i,N){
		int c,d;
		cin>>c>>d;
		if(c>d)swap(c,d);
		v.push_back({c,i});
		v.push_back({d,i});
	}
	sort(ALL(v));
	int ans = INF;
	set<int>st;
	int secondmi = INF,secondma = -1;
	REP(i,N*2){
		if(st.find(v[i].second) != st.end()){
			secondma = v[i].first;
			break;
		}
		st.insert(v[i].second);
	}
	st.clear();
	RREP(i,N*2){
		if(st.find(v[i].second) != st.end()){
			secondmi = v[i].first;
			break;
		}
		st.insert(v[i].second);
	}
	st.clear();
	vector<int>cnt(N,0);
	int right = 0;
    for (int left = 0; left < 2 * N; ++left) {
        while (right < 2 * N && st.size() < N) {
			st.insert(v[right].second);
			cnt[v[right].second]++;
            ++right;
        }
		if(right == 2 * N && st.size() < N)break;
		if(left == 0){
			CHMIN(ans,(v[right-1].first-v[0].first)*(v[2*N-1].first-secondma));
		}else if(right == 2 * N){
			CHMIN(ans,(v[right-1].first-v[left].first)*(secondmi-v[0].first));
		}else{
			CHMIN(ans,(v[right-1].first-v[left].first)*(v[2*N-1].first-v[0].first));
		}
		if(--cnt[v[left].second] == 0)st.erase(v[left].second);
    }
	cout << ans << endl;
}
