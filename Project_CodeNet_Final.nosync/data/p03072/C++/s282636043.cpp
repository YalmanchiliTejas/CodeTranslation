
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;

#define lint long long
#define INF 1000000000000000
#define pii pair<long long,long long>
#define all(x) (x).begin(),(x).end

/* source code below */

int main() {

	int N; cin >> N;
	vector<int> H(N); 
	for (int i = 0; i < N; i++)
	{
		cin >> H[i];
	}
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		bool check = true;
		for (int j = 0; j < i; j++)
		{
			if (!(H[i] >= H[j])) {
				check = false;
			}
		}
		if (check) count++;

	}
	cout << count << endl;
}
/* Don't forget to delete the header! */