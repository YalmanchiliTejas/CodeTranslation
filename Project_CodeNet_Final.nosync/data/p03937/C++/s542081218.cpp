#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<tuple>
#include<map>
#include<set>
#include<algorithm>
 
#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<=n;i++)
#define all(c) c.begin(), c.end()
#define MOD 1000000007
#define MAX 1000000001
#define INF 1410065408
 
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
struct edge{int from, to; ll cost;};
 
signed main(){
	int H, W;
	cin >> H >> W;
	vector<string> s(H);
	map<P, int> count;
	int sharp = 0;
	rep(H){
		cin >> s[i];
		repp(j, W){
			if(s[i][j] == '#'){
				sharp++;
				count[P(i,j)] = 1;
			}
		}
	}
	
	queue<P> que;
	que.push(P(0, 0));
	bool success = false;
	while(!que.empty()){
		P t = que.front();que.pop();
		int h = t.first, w = t.second;
		//cout << h << w << " " << count[P(h,w)] << endl;
		if(count[P(h, w)] == sharp){
			success = true;
			break;
		}
		if(w+1 < W && s[h][w+1] == '#'){
			count[P(h,w+1)] = count[P(h,w)] + 1;
			que.push(P(h, w+1));
		}
		if(h+1 < H && s[h+1][w] == '#'){
			count[P(h+1,w)] = count[P(h,w)] + 1;
			que.push(P(h+1, w));
		}
	}
	if(success){
		cout << "Possible";
	}else{
		cout << "Impossible";
	}
}