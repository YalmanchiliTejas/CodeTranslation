#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<llint, llint> P;

llint a, b;
llint n, s, t;
llint distS[305], distT[305];
priority_queue<P, vector<P>, greater<P> > Q;
vector<llint> ans;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> s >> t;
	
	llint res;
	for(int i = 1; i <= n; i++){
		cout << "? " << s << " " << i << endl;
		cin >> distS[i];
	}
	for(int i = 1; i <= n; i++){
		cout << "? " << t << " " << i << endl;
		cin >> distT[i];
	}
	
	llint D = distS[t];
	for(int i = 1; i <= n; i++){
		if(distS[i] + distT[i] == D) Q.push(make_pair(distS[i], i));
	}
	
	llint p = s;
	while(p != t){
		cout << "? " << p << " " << Q.top().second << endl;
		cin >> res;
		if(res == Q.top().first - distS[p]){
			ans.push_back(Q.top().second);
			p = Q.top().second;
		}
		Q.pop();
	}
	cout << "!";
	for(int i = 0; i < ans.size(); i++){
		cout << " " << ans[i];
	}
	cout << endl;
	
	return 0;
}
