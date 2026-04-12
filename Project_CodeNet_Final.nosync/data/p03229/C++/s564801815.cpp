#include<iostream>
#include<iomanip>
#include<algorithm>
#include<string>
#include<cmath>
#include<map>
#include<queue>
#include<set>
#include<vector>
#include<cstdio>

using namespace std;
/*
int find(int x, vector<int> &p) {
if (p[x] == x)return x;
return p[x] = find(p[x], p);
}

void uni(int x, int y, vector<int> &p) {
x = find(x, p);
y = find(y, p);
p[x] = y;
}

int same(int x, int y, vector<int> p) {
if (find(x, p) == find(y, p))return 1;
return 0;
}
*/

//long long a[1002];


int main()
{
	long long N, cnt = 0, tmp, ans = 0;

	cin >> N;

	vector<long long> a(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	long long sum = 0;
	vector<long long> b(N);
	for (int i = 0; i < N / 2; i++) {
		b[N / 2 - 1 - 2 * ((i + 1) / 2 * (int)pow(-1, i))] = a[i];
		b[N / 2 + 2 * ((i + 1) / 2 * (int)pow(-1, i))] = a[N - 1 - i];
		//cout << N / 2 - 1 - 2 * ((i + 1) / 2 * (int)pow(-1, i)) << ", " << N / 2 + 2 * ((i + 1) / 2 * (int)pow(-1, i)) << endl;
		//cout << i << ", " << N -1 -i << endl;
	}


	if (N % 2 == 0) {
		for (int i = 0; i < N - 1; i++) {
			sum += abs(b[i] - b[i + 1]);
		}
		cout << sum;
	}
	else {
		for (int i = 0; i < N - 2; i++) {
			sum += abs(b[i] - b[i + 1]);
		}
		sum += max(abs(a[N/2] - b[0]), abs(a[N / 2] - b[N-2]));
		cout << sum;
	}

	char qq;
	cin >> qq;
	return 0;
}