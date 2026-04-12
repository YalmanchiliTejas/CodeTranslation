#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<cmath>
#include<string>

using namespace std;

#define maxn l005
#define ll long long

vector<string> v;

int vis[60][30];
int sum[30];

int main() {
	int n;
	scanf("%d", &n);
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			vis[i][str[j] - 'a']++;
		}
	}

	for (int j = 0; j < 26; j++) {
		sum[j] = 100;
		for (int i = 1; i <= n; i++) {
			sum[j] = min(sum[j], vis[i][j]);
		}
	}

	for (int i = 0; i < 26; i++)
		for (int j = 1; j <= sum[i]; j++)
			cout << (char)('a' + i);

	puts("");
	return 0;
}