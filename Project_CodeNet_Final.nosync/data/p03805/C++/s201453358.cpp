#include<bits/stdc++.h>

#define INF 1000000007
#define LINF 1000000000000000007

using namespace std;

typedef long long Int;
typedef pair<Int, Int> P;

Int gcd(Int x, Int y){
	if(y == 0)
		return x;
	return gcd(y, x % y);
}

Int lcm(Int x, Int y){
	return x * y / gcd(x, y);
}

bool sosuu(int x){
	bool b = 1;
	if(x == 1) b = 0;
	for(int i = 2; i * i <= x; i++){
		if(x % i == 0) {
			b = 0;
			break;
		}
	}
	return b;
}

int n, m;
bool can[9][9] = {0};

int main(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		can[a][b] = 1;
		can[b][a] = 1;
	}
	
	queue<P> q;
	q.push(make_pair(1, 1));
	int ans = 0;
	while(q.size()){
		P now = q.front();
		q.pop();
		if(now.second == (1 << n) - 1) ans++;
		for(int i = 1; i < n; i++){
			if(can[now.first][i+1] && !((now.second >> i) & 1)){
				q.push(make_pair(i+1, now.second + (1 << i)));
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}