#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
#define loop(i,a,b) for(int i=(a);i<ull(b);++i)
#define rep(i,n) loop(i,0,n)
#define all(a) (a).begin(), (a).end()

const double eps = 1e-10;
const double pi  = acos(-1.0);
const double inf = (int)1e8;

int main(){
	int a, b;
	vector<pair<int, int> > v;
	while(true){
		scanf("%d,%d", &a, &b);
		if(a == 0 && b == 0) break;
		v.push_back(make_pair(b, a));
	}
	sort(all(v), greater<pair<int, int> >() );
	vector<int> rank(v.size());

	int r = 1;
	rank[0] = r;
	for(int i=1; i< v.size(); i++){
		if(v[i].first != v[i-1].first) r++;
		rank[i] = r;
	}

	int n;
	while(cin >> n){
		for(int i=0; i < v.size(); i++) if(n == v[i].second){cout << rank[i] << endl; break;}
	}
}