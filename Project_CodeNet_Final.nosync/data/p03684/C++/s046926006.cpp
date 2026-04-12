/*input
6
8 3
4 9
12 19
18 1
13 5
7 6
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 100007;

int Arr[N], sizee[N], n, ans;
pair<pair<int, int>, int> point[N];
vector<pair<int, pair<int, int> > > edges;

void initialize_dsu(int a, int b) {for(int i=a; i<=b; ++i) Arr[i] = i, sizee[i] = 1;}
int root(int a) { if(a == Arr[a]) return a; return Arr[a] = root(Arr[a]);}
bool find(int a, int b) {return (root(a) == root(b));}
void union_set(int a, int b){
	int u = root(a), v = root(b); if(find(u, v)) return;
	if(sizee[u] < sizee[v]) swap(u, v); Arr[v] = Arr[u], sizee[u] += sizee[v];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n; initialize_dsu(1, n);
	for(int i=1; i<=n; ++i)
		cin >> point[i].first.first >> point[i].first.second, point[i].second = i;
	sort(point + 1, point + n + 1);
	swap(point[1].first.first, point[1].first.second);
	for(int i=2; i<=n; ++i)
		swap(point[i].first.first, point[i].first.second),
		edges.push_back(make_pair(point[i].first.second - point[i-1].first.second, make_pair(point[i].second, point[i-1].second)));
	
	sort(point + 1, point + n + 1);
	for(int i=2; i<=n; ++i) 
		edges.push_back(make_pair(point[i].first.first - point[i-1].first.first, make_pair(point[i].second, point[i-1].second)));
	
	sort(edges.begin(), edges.end());
	for(auto &v:edges){
		if(find(v.second.second, v.second.first)) continue;
		union_set(v.second.first, v.second.second); ans += v.first;
	}
	cout << ans << endl;
	return 0;
}