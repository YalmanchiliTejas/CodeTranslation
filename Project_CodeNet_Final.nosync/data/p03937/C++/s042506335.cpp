#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cmath>
#include<cstring>
#include<queue>
#include<map>
#include<set>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)

using namespace std;
typedef pair<int, int> pii;

typedef long long int ll;

template<typename T>
vector<T> make_v(size_t a) { return vector<T>(a); }
template<typename T, typename... Ts>
auto make_v(size_t a, Ts... ts) {
	return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}
template<typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type
fill_v(T& t, const V& v) { t = v; }
template<typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type
fill_v(T& t, const V& v) {
	for (auto& e : t) fill_v(e, v);
}


#define ARRAY_MAX 5005
const ll INF = 1e9 + 7;


int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };

const ll MOD = 1e9 + 7;

int h, w;
char mp[10][10];
int check[10][10];

int main() {

	cin >> h >> w;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> mp[i][j];
		}
	}


	queue<pii> que;

	que.push(pii(0, 0));

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			check[i][j] = -1;
		}
	}
	check[0][0] = 1;

	while (!que.empty())
	{
		int y = que.front().first;
		int x = que.front().second;
		que.pop();
		//cout << y << " " << x << endl;
		if (y == h - 1 && x == w - 1)
		{
			break;
		}
		//cout << "a" << endl;
		if (x + 1 < w && mp[y][x + 1] == '#' && check[y][x+1] == -1)
		{
			//cout << "a" << endl;
			que.push(pii(y, x + 1));
			check[y][x + 1] = 1;
		}
		else if (y + 1 < h && mp[y + 1][x] == '#'&& check[y + 1][x] == -1)
		{
			//cout << "b" << endl;
			que.push(pii(y + 1, x));
			check[y + 1][x] = 1;
		}
		else
		{
			//cout << "c" << endl;
			cout << "Impossible" << endl;
			return 0;
		}
	}

	/*for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cout << check[i][j] << " ";
		}
		cout << endl;
	}*/

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j  < w; j ++)
		{
			if (mp[i][j] == '#' && check[i][j] == -1)
			{
				cout << "Impossible" << endl;
				return 0;
			}
		}
	}


	cout << "Possible" << endl;




	return 0;
}

