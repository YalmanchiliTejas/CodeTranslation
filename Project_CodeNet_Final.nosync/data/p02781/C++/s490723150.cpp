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
		//cout << "x0: " << x0 << ", bounded0: " << bounded0 << '\n';
		for(int v0 = 1; v0 <= (bounded0 ? (Nstr[x0] - '0') : 9); ++v0) {
			//cout << "v0: " << v0 << '\n';
			if(K == 1) {
				++ans0;
			} else {
				bool bounded1 = (bounded0 && (v0 == Nstr[x0] - '0'));
				for(int x1 = x0 + 1; x1 < Nstr.length(); ++x1) {
					long long ans1 = 0;
					//cout << "x1: " << x1 << ", bounded1: " << bounded1 << '\n';
					for(int v1 = 1; v1 <= (bounded1 ? (Nstr[x1] - '0') : 9); ++v1) {
						//cout << "v1: " << v1 << '\n';
						if(K == 2) {
							++ans1;
						} else {
							bool bounded2 = (bounded1 && (v1 == Nstr[x1] - '0'));
							for(int x2 = x1 + 1; x2 < Nstr.length(); ++x2) {
								long long ans2 = 0;
								for(int v2 = 1; v2 <= (bounded2 ? (Nstr[x2] - '0') : 9); ++v2) {
									++ans2;
								}
								//cout << "ans2: " << ans2 << '\n';
								ans1 += ans2;
								if(bounded2 && Nstr[x2] != '0') bounded2 = false;
							}
						}
					}
					//cout << "ans1: " << ans1 << '\n';
					ans0 += ans1;
					if(bounded1 && Nstr[x1] != '0') bounded1 = false;
				}
			}
		}
		//cout << "ans0: " << ans0 << '\n';
		ans += ans0;
	}
	cout << ans << '\n';
	return 0;
	//
	switch(K) {
		case 1:
			for(int i = 0; i < Nstr.length(); ++i) {
				if(i == 0) {
					ans += Nstr[i] - '0';
				} else {
					ans += 9;
				}
			}
			break;
		case 2:
			for(int i = 0; i < Nstr.length(); ++i) {
				long long ans2 = 0;
				long long ans2m = 0;
				for(int j = i + 1; j < Nstr.length(); ++j) {
					if(j == i + 1) {
						ans2m += Nstr[j] - '0';
					} else {
						ans2m += 9;
					}
					ans2 += 9;
				}
				if(i == 0) {
					ans += ((Nstr[i] - '0') - 1) * ans2 + ans2m;
				} else {
					ans += 9 * ans2;
				}
			}
			break;
		case 3:
			for(int i = 0; i < Nstr.length(); ++i) {
				long long ans2 = 0;
				long long ans2m = 0;
				for(int j = i + 1; j < Nstr.length(); ++j) {
					long long ans3 = 0;
					long long ans3m = 0;
					for(int k = j + 1; k < Nstr.length(); ++k) {
						if(j == i + 1 && k == j + 1) {
							ans3m += Nstr[k] - '0';
						} else {
							ans3m += 9;
						}
						ans3 += 9;
					}
					if(j == i + 1) {
						ans2 += ((Nstr[i] - '0') - 1) * ans2 + ans2m;
					} else {
						ans2 += 9 * ans2;
					}
					if(j == i + 1) {
						ans2m += Nstr[j] - '0';
					} else {
						ans2m += 9;
					}
					ans2 += 9;
				}
				if(i == 0) {
					ans += ((Nstr[i] - '0') - 1) * ans2 + ans2m;
				} else {
					ans += 9 * ans2;
				}
			}
			break;
	}
	cout << ans << '\n';
	return 0;
}

