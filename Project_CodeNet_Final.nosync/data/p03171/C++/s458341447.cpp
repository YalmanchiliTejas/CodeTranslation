#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

//#define FILE_INPUT
//#define DEBUG_MODE

void DebugPrint(double a[], int n)
{
#ifdef DEBUG_MODE
	for (int i = 0; i < min(20, n); ++i) {
		cout << a[i] << ",";
	}
	cout << endl;
#endif
}

long long int memo[3000][3000];
bool valid[3000][3000];

long long int Comp(int n, vector<int> &a, int head, int tail)
{
	if (valid[head][tail]) {
		return memo[head][tail];
	}

	if (head == tail) {
		return a[head];
	}
	long long int score1 = a[head] - Comp(n, a, head + 1, tail);
	long long int score2 = a[tail] - Comp(n, a, head, tail - 1);
	long long int max_score = max(score1, score2);
	//cout << head << " " << tail << " " << max_score << endl;

	memo[head][tail] = max_score;
	valid[head][tail] = true;

	return max_score;
}


int main()
{
#ifdef FILE_INPUT
	ifstream in("test3.txt");
	cin.rdbuf(in.rdbuf());
#endif	/* FILE_INPUT */  

	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int head = 0;
	int tail = n - 1;
	long long int score = Comp(n, a, head, tail);

	cout << score << endl;

	return 0;
}
