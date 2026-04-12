#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 100000

int main(void){
	int n;
	cin >> n;
	vector<string> a(n);
	string b;
	int alp[n][27];
	int ans[27];

	for(int i = 0; i < n; i++){
		cin >> a[i];
		for(int j = 0; j < 26; j++){
			alp[i][j] = 0;
		}
		for(int j = 0; j < a[i].length(); j++){
			alp[i][a[i][j] - 'a']++;
		}
	}
	for(int i = 0; i < 26; i++){
		ans[i] = INF;
	}

	for(int i = 0; i < 26; i++){
		for(int j = 0; j < n; j++){
			if(alp[j][i] < ans[i]){
				ans[i] = alp[j][i];
			}
		}
	}
	for(int i = 0; i < 26; i++){
		while(ans[i] > 0){
			char t = i + 'a';
			cout << t;
			ans[i]--;
		}
	}
	cout << endl;
	return 0;
}