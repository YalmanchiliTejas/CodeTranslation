#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#define MOD 1000000007
using namespace std;

int main()
{
	int n;
	int flag = 0;
	string s;
	cin >> n;
	cin >> s;
	int i,j,k,l;
	s += s[0];
	std::string ans(n, 'a');
	ans += '0';
	ans += '0';
	ans[0] = 's';
	ans[1] = 's';
	for (i = 0; i < n; i++){
		if (ans[i+1] == 's'){
			if (ans[i] == 's'){
				if (s[i + 1] == 'o'){
					ans[i + 2] = 's';
				}
				else{
					ans[i + 2] = 'w';
				}
			}
			else{
				if (s[i + 1] == 'o'){
					ans[i + 2] = 'w';
				}
				else{
					ans[i + 2] = 's';
				}
			}
		}
		else{
			if (ans[i] == 's'){
				if (s[i + 1] == 'o'){
					ans[i + 2] = 'w';
				}
				else{
					ans[i + 2] = 's';
				}
			}
			else{
				if (s[i + 1] == 'o'){
					ans[i + 2] = 's';
				}
				else{
					ans[i + 2] = 'w';
				}
			}
		}
	}
	if (ans[n] == 's'&&ans[n + 1] == 's'){
		ans.pop_back();
		ans.pop_back();
	}
	else{
		ans[0] = 's';
		ans[1] = 'w';
		for (i = 0; i < n; i++){
			if (ans[i + 1] == 's'){
				if (ans[i] == 's'){
					if (s[i + 1] == 'o'){
						ans[i + 2] = 's';
					}
					else{
						ans[i + 2] = 'w';
					}
				}
				else{
					if (s[i + 1] == 'o'){
						ans[i + 2] = 'w';
					}
					else{
						ans[i + 2] = 's';
					}
				}
			}
			else{
				if (ans[i] == 's'){
					if (s[i + 1] == 'o'){
						ans[i + 2] = 'w';
					}
					else{
						ans[i + 2] = 's';
					}
				}
				else{
					if (s[i + 1] == 'o'){
						ans[i + 2] = 's';
					}
					else{
						ans[i + 2] = 'w';
					}
				}
			}
		}
		if (ans[n] == 's'&&ans[n + 1] == 'w'){
			ans.pop_back();
			ans.pop_back();
		}
		else{
			ans[0] = 'w';
			ans[1] = 's';
			for (i = 0; i < n; i++){
				if (ans[i + 1] == 's'){
					if (ans[i] == 's'){
						if (s[i + 1] == 'o'){
							ans[i + 2] = 's';
						}
						else{
							ans[i + 2] = 'w';
						}
					}
					else{
						if (s[i + 1] == 'o'){
							ans[i + 2] = 'w';
						}
						else{
							ans[i + 2] = 's';
						}
					}
				}
				else{
					if (ans[i] == 's'){
						if (s[i + 1] == 'o'){
							ans[i + 2] = 'w';
						}
						else{
							ans[i + 2] = 's';
						}
					}
					else{
						if (s[i + 1] == 'o'){
							ans[i + 2] = 's';
						}
						else{
							ans[i + 2] = 'w';
						}
					}
				}
			}
			if (ans[n] == 'w'&&ans[n + 1] == 's'){
				ans.pop_back();
				ans.pop_back();
			}
			else{
				ans[0] = 'w';
				ans[1] = 'w';
				for (i = 0; i < n; i++){
					if (ans[i + 1] == 's'){
						if (ans[i] == 's'){
							if (s[i + 1] == 'o'){
								ans[i + 2] = 's';
							}
							else{
								ans[i + 2] = 'w';
							}
						}
						else{
							if (s[i + 1] == 'o'){
								ans[i + 2] = 'w';
							}
							else{
								ans[i + 2] = 's';
							}
						}
					}
					else{
						if (ans[i] == 's'){
							if (s[i + 1] == 'o'){
								ans[i + 2] = 'w';
							}
							else{
								ans[i + 2] = 's';
							}
						}
						else{
							if (s[i + 1] == 'o'){
								ans[i + 2] = 's';
							}
							else{
								ans[i + 2] = 'w';
							}
						}
					}
				}
				if (ans[n] == 'w'&&ans[n + 1] == 'w'){
					ans.pop_back();
					ans.pop_back();
				}
				else{
					cout << -1 << endl;
					flag = 1;
				}
			}
		}
	}
	for (i = 0; i < n; i++){
		if (ans[i] == 's'){
			ans[i] = 'S';
		}
		else{
			ans[i] = 'W';
		}
	}
	if (flag == 0){
		cout << ans << endl;
	}


	return 0;
}