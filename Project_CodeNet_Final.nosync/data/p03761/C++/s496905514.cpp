#include <bits/stdc++.h>

typedef long long ll;
const int MAX_N = 50;

int main() {
	int n, cnt[26];
	std::string S[MAX_N], alphabet = "abcdefghijklmnopqrstuvwxyz";
	std::cin >> n;
	for(int i = 0; i < n; ++i) {
		std::cin >> S[i];
	}

	for(int i = 0; i < 26; ++i) {
		cnt[i] = 50;
		for(int j = 0; j < n; ++j) {
			int tmp = 0;
			for(char c : S[j]) {
				if(c == alphabet[i]) ++tmp;
			}
			cnt[i] = std::min(cnt[i], tmp);
		}
	}

	for(int i = 0; i < 26; ++i) {
		for(int j = 0; j < cnt[i]; ++j) {
			std::cout << alphabet[i];
		}
	} std::cout << std::endl;

}
