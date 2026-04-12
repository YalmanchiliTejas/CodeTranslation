#include <bits/stdc++.h>
#define ll long long
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

const int N = 500001, M = 300000;
int nc = 0;
int rep[N], sz[N];
pair<int, pair<int, int> > p[M];
int sum;

int findu(int u){
    return rep[u] = (rep[u] == u ? u : findu(rep[u]));
}

void join(int a, int b){
    a = findu(a);
    b = findu(b);
    if (a == b)
        return;
    if (sz[a] < sz[b])
        swap(a, b);
    rep[b] = a;
    sz[a] += sz[b];
    nc--;
}
void mst(){
    sort(p, p + M);
    for (int i = 0; i < M; i++){
       int a = p[i].second.first;
       int b = p[i].second.second;
       if (rep[a] != rep[b])
            join(a, b);
       else
        sum += p[i].first;
    }
}

int main() {
	IO
	int n, x, y;
	cin >> n;
	vector<pair<pair<int, int>, int > >vx, vy;
	map<int, vector<pair<int, int> > > mp;
	iota(rep, rep + N, 0);
	fill(sz, sz + N, 1);
	nc = n;
	for (int i = 0; i < n; i++){
        cin >> x >> y;
        vx.push_back({{x, y}, i});
        vy.push_back({{y, x}, i});

	}
	sort(vx.begin(), vx.end());
	sort(vy.begin(), vy.end());
	for (int i = 1; i < n; i++){
        int diff = abs(vx[i].first.first - vx[i - 1].first.first);
        mp[diff].push_back({vx[i].second, vx[i - 1].second});

	}
	for (int i = 1; i < n; i++){
        int diff = abs(vy[i].first.first - vy[i - 1].first.first);
        mp[diff].push_back({vy[i].second, vy[i - 1].second});
	}
	ll ans = 0;
	for (auto i : mp){
        for (auto j : i.second){
            int id1 = j.first, id2 = j.second;
            if (findu(id1) != findu(id2))
                join(id1, id2), ans += i.first;

        }
	}
	cout << ans;
	return 0;
}
