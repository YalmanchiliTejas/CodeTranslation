#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;
int main(){

	int N;
	cin >> N;
	vector<int>H(N);
	for (int i = 0; i < N; i++)
		cin >> H[i];

	priority_queue<int>que;
	int ans = 0;
	for (int i = 0; i < N; i++){
		que.push(H[i]);
		if (que.top() <= H[i])
			ans++;
	}

	cout << ans << endl;

	return 0;
}