#include <iostream>

using namespace std;
bool link[9][9];
int N, M;

int search(int num, int visited) {
	int ans = 0;
	bool end = true;
	int nowVisited = visited + (1 << (num-1));

	for (int i=1; i<=N; i++) {
		if ((nowVisited >> (i-1))%2 == 0) {
			end = false;
			break;
		}
	}
	if (end) {
		return 1;
	}
	for (int i=1; i<=N; i++) {
		if (link[num][i] && (nowVisited >> (i-1))%2==0) {
			ans += search(i, nowVisited);
		}
	}
	return ans;
}
int main(){
	int a[32], b[32];

	cin >> N >> M;
	for (int i=0; i<M; i++) {
		cin >> a[i] >> b[i];
		link[a[i]][b[i]] = link[b[i]][a[i]] = true;
	}
	int visited = 0;
	cout << search(1, visited) << endl;
	return 0;
}
	