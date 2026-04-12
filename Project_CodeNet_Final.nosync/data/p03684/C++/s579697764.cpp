#include <bits/stdc++.h>
#define f(a, n) for (int a=0; a<n; a++)
#define F(a, n) for (int a=1; a<=n; a++)
using namespace std;

int n;
int P[100005];
pair<int, int> X[100005];
pair<int, int> Y[100005];

int find(int x){
	if (P[x] == x) return x;
	return P[x] = find(P[x]);
}

bool join(int x, int y){
	int a = find(x), b = find(y);
	if (a == b) return 0;
	P[a] = P[b];
	return 1;
}

int main(){
	cin>>n;
	f(i, n) P[i] = i;
	f(i, n) {	
		cin>>X[i].first>>Y[i].first;
		X[i].second = Y[i].second = i;
	}
	sort(X, X+n);
	sort(Y, Y+n);
	vector<pair<int, pair<int, int>>> V;
	f(i, n-1){
		V.push_back({X[i+1].first - X[i].first, {X[i+1].second, X[i].second}});
		V.push_back({Y[i+1].first - Y[i].first, {Y[i+1].second, Y[i].second}});
	}
	long long ans = 0;
	sort(V.begin(), V.end());
	for (auto x: V){
		int c = x.first, y = x.second.first, z = x.second.second;
		if (join(y, z)) ans += c;
	}
	cout<<ans<<endl;
}