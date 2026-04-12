# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <set>
# include <cmath>
# include <iomanip>
# include <functional>
# include <utility>
# include <queue>
# define MOD 1000000000+7
# define INF 1000000000
#define rep(i,rept)	for(ll i = 0; i<rept;i++)
typedef long long ll;
using namespace std;
long long int a = 0, b = 0, c = 0, ans = 0, x = 0, y = 0, z = 0, n = 0, m = 0, maxy = 0, mini = 9999, counter = 0, endp = 0, checker = 0;

std::vector <char> vec{}, vecsec{}, vecth{};
long long int iremono[100001], sec[100001];
long long int iremono2[100001], check[100001];
std::vector<long long int>kinds{}, kaku{};
char maze[1000][1000];
int sx, sy;
int gx, gy;

bool relation[1000][1000];
int twod[1001][1001];
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
bool okada = false, okada2 = false;
std::string output, output2, input, input2;
char rev[100001];


int ctoi(const char c) {
	if ('0' <= c && c <= '9') return (c - '0');
	return -1;
}
unsigned long long int LCM(unsigned long long int a, unsigned long long int b) {
	unsigned long long int i, j;
	i = a; j = b;
	while (true) {

		c = i % j;
		i = j;
		if (c != 0) {

			j = c;

		}
		else {
			break;
		}
	}
	return j * (a / j) * (b / j);
}
int kaizyo(int k) {
	int sum = 1;
	for (int i = 1; i <= k; ++i)
	{
		sum *= i;
	}
	return sum;
}

int N, M;//はんい
int bfs() {
	queue<pair<int, int>> que;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			twod[i][j] = INF;
		}
	}
	que.push(pair<int, int>(sx, sy));
	twod[sx][sy] = 1;
	while (que.size()) {
		pair<int, int> p = que.front();
		que.pop();
		if (p.first == gy && p.second == gx) {
			break;
		}
		for (int i = 0; i < 4; i++) {
			int nx = p.first + dx[i], ny = p.second + dy[i];
			if (1 <= nx && nx <= N && 1 <= ny && ny <= M && maze[nx][ny] != '#'&&twod[nx][ny] == INF) {
				que.push(pair<int, int>(nx, ny));
				twod[nx][ny] = twod[p.first][p.second] + 1;
			}
		}
	}
	return twod[gy][gx];
}
vector <int> g[100100];
int main()
{
	cin >> a;
	rep(i, a) {
		cin >> iremono[i];
	}
		maxy = iremono[0];
	rep(i, a) {
		if (iremono[i] >= maxy) {
			counter++;
			maxy = iremono[i];
		}
	}
	cout << counter << endl;



}