#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(N) for (int i = 0; i < N; i++)

int main() {
	int N, M;
	int a, b;
	int count = 0;
	cin >> N >> M;
	vector<vector<int>> graph_metrix(N, vector<int>(N));
	vector<int> front_path;
	vector<int> added_path;
	list<vector<int>> paths;
	paths.push_back({0});
	for (int i = 0; i < M; i++){
		cin >> a >> b;
		graph_metrix[a-1][b-1] = 1;
		graph_metrix[b-1][a-1] = 1;
	}
	while (paths.size() != 0){
		front_path = paths.front();
		/*
		for (int x: front_path){
			cout << to_string(x) << " ";
		}
		cout << endl;
		*/
		for (int i = 0; i < N; i++){
			if (graph_metrix[front_path.back()][i] == 1){
				if (find(front_path.begin(), front_path.end(), i) == front_path.end()){
					added_path = front_path;
					added_path.push_back(i);
					paths.push_back(added_path);
					if (added_path.size() == N) count++;
				}
			}
		}
		paths.pop_front();
	}
	cout << count << endl;
}
