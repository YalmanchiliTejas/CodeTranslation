#include<iostream>
#include<algorithm>
using namespace std;

const int MAX = 200000;
int main() {
	int N;
	static int A[MAX], tmp[MAX];
	cin >> N;
	for (int i = 0;i < N;i ++) {
		cin >> A[i];
		tmp[i] = A[i];
	}
	sort(tmp, tmp+N);
	for (int i = 0;i < N;i ++) {
		if (A[i] <= tmp[N / 2 - 1]) cout << tmp[N / 2];
		else cout << tmp[N / 2 - 1];
		if (i < N - 1) cout << endl;
	}
	
	return 0;
}
/*
31536000のコメント解説欄
ここテンプレで用意してるから、A問題とかだとこの先空欄の危険あり

まず、全体をソートしたと仮定し、これを{X}とします
この時、中央値はX_(N/2)かX_(N/2+1)にしかなりません

後は、各A_iについてX_(N/2)以下ならX_(N/2+1)、そうでないならX_(N/2)が答えになります
*/