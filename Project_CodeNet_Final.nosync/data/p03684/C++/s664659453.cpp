#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int, int> pii;

#define erep(i, x, n) for (auto i = x; i<=(ll)(n); i++)
#define rep(i, x, n) for(auto i = x; i<(ll)(n); i++)
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define mod(n, m) (((n%m) + m)%m)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'

const int N = 1e5 + 5;

vector<pair<ll, int>> node[N];
map<pii, int> idx;
set<pair<ll, int>> st;
vector<pii> vec;

int n, curr = 1;
bool visited[N];

void explore(int v)
{
	visited[v] = true;
	for (auto i : node[v])
		if (!visited[i.second])
			st.insert(
			{ i.first, i.second });
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	vec.resize(n);
	rep(i, 0, n)
	{
		int a, b;
		cin >> a >> b;

		if (!idx[
		{ a, b }])
			idx[
			{ a, b }] = curr++;
		vec[i] =
		{	a, b};
	}

	sort(all(vec));

	rep(i, 0, n-1)
	{
		int a = idx[vec[i]], b = idx[vec[i + 1]];
		int val = min(abs(vec[i].first - vec[i + 1].first),
				abs(vec[i].second - vec[i + 1].second));

		node[a].push_back(
		{ val, b });
		node[b].push_back(
		{ val, a });
	}

	rep(i, 0, n)
		swap(vec[i].first, vec[i].second);

	sort(all(vec));
	rep(i, 0, n-1)
	{
		int a = idx[
		{ vec[i].second, vec[i].first }], b = idx[
		{ vec[i + 1].second, vec[i + 1].first }];

		int val = min(abs(vec[i].first - vec[i + 1].first),
				abs(vec[i].second - vec[i + 1].second));

		node[a].push_back(
		{ val, b });
		node[b].push_back(
		{ val, a });
	}

	explore(1);

	ll mst = 0;
	// cost, idx, par if needed
	while (!st.empty())
	{
		auto i = st.begin();
		st.erase(st.begin());

		ll cost = i->first, idx = i->second;

		if (!visited[idx])
		{
			mst += cost;
			explore(idx);
		}
	}

	cout << mst << endl;

	return 0;
}
