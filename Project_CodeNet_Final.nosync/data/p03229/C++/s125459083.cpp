#include <iostream>
#include <iomanip>
#include <utility>
#include <cmath>
#include <random>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

#define rep(i,n) for(int i = 0; i<n; ++i)
#define REP(i,n) for(int i = 1; i<=n; ++i)
#define all(x) begin(x),end(x)
#define show(obj) {for(auto x:obj)cout<<x<<' ';cout<<endl;}
#define line "----------"
typedef long long ll;
typedef pair<int,int> P;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const ll MOD = 1e9 + 7;

vector<int> input;
int N;

ll solve(int siz){
	deque<ll> P,Q;
	rep(i,N)P.push_back(input[i]);
	if(siz>0){
		Q.push_back(P.front());
		P.pop_front();
	}else{
		Q.push_back(P.back());
		P.pop_back();
	}
	// show(Q);
	while(!P.empty()){
		if(siz > 0){
			if(P.size()<2){
				ll t = P.back(); P.pop_back();
				if(abs(Q.front()-t) > abs(Q.back()-t)){
					Q.push_front(t);
				}else{
					Q.push_back(t);
				}
				break;
			}
			ll mb = P.back(); P.pop_back();
			ll lb = P.back(); P.pop_back();
			Q.push_front(mb);
			Q.push_back(lb);
		}else{
			if(P.size()<2){
				ll t = P.back(); P.pop_back();
				if(abs(Q.front()-t) > abs(Q.back()-t)){
					Q.push_front(t);
				}else{
					Q.push_back(t);
				}
				break;
			}
			ll ms = P.front(); P.pop_front();
			ll ls = P.front(); P.pop_front();
			Q.push_front(ms);
			Q.push_back(ls);
		}
		siz *= -1;
	}
	// show(Q);
	ll ans = 0;
	ll bf = Q.front();
	Q.pop_front();
	while(!Q.empty()){
		ans += abs(bf-Q.front());
		bf = Q.front();
		Q.pop_front();
	}
	return ans;
}

int main(){
	cin>>N;
	input.resize(N);
	rep(i,N)cin>>input[i];
	sort(all(input));
	ll ans_a = solve(1);
	ll ans_b = solve(-1);
	cout<<max(ans_a, ans_b)<<endl;
	return 0;
}