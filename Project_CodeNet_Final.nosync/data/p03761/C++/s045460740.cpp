#include <bits/stdc++.h>
using namespace std;

const int INF = 1 << 30;

vector<vector<int> > bucket(50, vector<int>(26, 0));
vector<int> a(26, INF);

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for(auto c: s)
			bucket[i][c - 'a']++;
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 26; j++) {
			a[j] = min(a[j], bucket[i][j]);
		}
	}
	for(int i = 0; i < 26; i++) {
		if(a[i] != INF) {
			for(int j = 0; j < a[i]; j++)
				printf("%c", i + 'a');
		}
	}
	printf("\n");
}
