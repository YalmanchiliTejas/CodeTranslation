#include<bits/stdc++.h>
using namespace std;
int main() {
	int N; cin >> N;
	int H[N];
	for(int i = 0; i < N; i++) cin >> H[i];
	int max = 0, sea = 0;
	for (int i = 0; i < N; i++)
	{
		if(max <= H[i]) {
			max = H[i];
			sea++;
		}
	}
	cout << sea << endl;
	return 0;
}
