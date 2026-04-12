#include<iostream>
#include<vector>
using namespace std;
void dfs(int place, int pass);
vector<int>graph[8];
int flag[8];
int n, m;
int counter = 0;

int main() {


	cin >> n >> m;

	int a, b;
	int i;
	for (i = 0; i < m; i++) {
		cin >> a >> b;
		graph[a - 1].push_back(b - 1);
		graph[b - 1].push_back(a - 1);
	}

	//0が始点

	//int pass = 0;
	//int place = 0;
	for (i = 0; i < n; i++) {
		flag[i] = 0;
	}
    flag[0] = 1;
	counter = 0;
	dfs(0, 1);
	cout << counter << endl;
	return 0;
}
void dfs(int place, int pass) {
	int i;
	for (i = 0; i < graph[place].size(); i++) {
		if (flag[graph[place][i]] == 0) {
			flag[graph[place][i]] = 1;
			//pass++;
			//place = graph[place][i];
			if (pass == n - 1) {
				counter++;
              //cout << 'a' << place << ' ' << pass << endl;
			}
			else {
				dfs(graph[place][i], pass + 1);
              //cout << 'b' << place << ' ' << pass  << endl;
			}
			flag[graph[place][i]] = 0;
		}
	}
}