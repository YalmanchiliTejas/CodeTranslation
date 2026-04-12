#include <bits/stdc++.h>

using namespace std;

int main(void) {
	string Nstr;
	cin >> Nstr;
	int K;
	cin >> K;
	long long ans = 0;
	bool bounded0 = true;
	for(int x0 = 0; x0 < Nstr.length(); ++x0) {
		long long ans0 = 0;
		bounded0 = (x0 == 0);
		for(int v0 = 1; v0 <= (bounded0 ? (Nstr[x0] - '0') : 9); ++v0) {
			if(K == 1) {
				++ans0;
			} else {
				bool bounded1 = (bounded0 && (v0 == Nstr[x0] - '0'));
				for(int x1 = x0 + 1; x1 < Nstr.length(); ++x1) {
					long long ans1 = 0;
					for(int v1 = 1; v1 <= (bounded1 ? (Nstr[x1] - '0') : 9); ++v1) {
						if(K == 2) {
							++ans1;
						} else {
							bool bounded2 = (bounded1 && (v1 == Nstr[x1] - '0'));
							for(int x2 = x1 + 1; x2 < Nstr.length(); ++x2) {
								long long ans2 = 0;
								for(int v2 = 1; v2 <= (bounded2 ? (Nstr[x2] - '0') : 9); ++v2) {
									++ans2;
								}
								ans1 += ans2;
								if(bounded2 && Nstr[x2] != '0') bounded2 = false;
							}
						}
					}
					ans0 += ans1;
					if(bounded1 && Nstr[x1] != '0') bounded1 = false;
				}
			}
		}
		ans += ans0;
	}
	cout << ans << '\n';
	return 0;
}

