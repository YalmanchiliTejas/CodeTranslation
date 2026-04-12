#include <bits/stdc++.h>
using namespace std;

int N, L[26];

int main(){
	cin >> N;
	memset(L, 10000, sizeof(L));
	for(int i = 0; i < N; i++){
		string st;
		cin >> st;
		int let[26];
		memset(let, 0, sizeof(let));
		for(int j = 0; j < st.length(); j++) let[st[j] - 'a']++;
		for(int j = 0; j < 26; j++) L[j] = min(L[j], let[j]);
	}
	for(int i = 0; i < 26; i++)
		for(int j = 0; j < L[i]; j++) printf("%c", (char)('a' + i));
	printf("\n");
	return 0;
}
