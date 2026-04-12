#include<iostream>
using namespace std;
int graph[10][10];
int N, M;
int func(int p, int pass[10]) {
	bool flag = true;
	for (int i = 0; i < N; i++) if (pass[i] == 0)flag = false;
	if (flag)return 1;
	int passed[10];
	for (int i = 0; i < N; i++)passed[i] = pass[i];
	int route = 0;
	for (int i = 0; i < N; i++) {
		if (graph[p][i] == 1 && passed[i] == 0) {
			passed[i] = 1;
			route += func(i, passed);
			passed[i] = 0;
		}
	}
	return route;
}
int main() {
	cin >> N >> M;
	int pass[10];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			graph[i][j] = 0;
		}
	}
	pass[0] = 1;
	for (int i = 1; i < N; i++)pass[i] = 0;
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		graph[a - 1][b - 1] = 1;
		graph[b - 1][a - 1] = 1;
	}
	cout << func(0, pass) << endl;
}