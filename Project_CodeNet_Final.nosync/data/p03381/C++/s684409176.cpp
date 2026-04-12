#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;
int n, x[N], ind[N];
vector<pair<int, int> > v;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> x[i];
		v.push_back({x[i], i});
	}	
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
		ind[v[i].second] = i;
		
	int m = (n + 1) / 2;
	m--;
	//cout << m << endl;
	
	for (int i = 0; i < n; i++){
		if(ind[i] <= m)
			cout << v[m + 1].first << ' ';
		else
			cout << v[m].first << ' ';
	}
}
