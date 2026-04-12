#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main(){
	int n;
	string ans = "";
	cin >> n;
	vector<string> s(n);
	for(int i = 0; i < n; i++){
		cin >> s[i];
	}
	vector<int> a(26);
	for(int i = 0; i < n; i++){
		vector<int> b(26, 0);
		for(int j = 0; j < s[i].size(); j++){
			int p = s[i][j] - 'a';
			b[p]++;
		}
		if(i == 0){
			a = b;
		}else{
			for(int j = 0; j < 26; j++){
				a[j] = min(a[j], b[j]);
			}
		}
	}
	for(int i = 0; i < 26; i++){
		for(int j = 0; j < a[i]; j++){
			ans += ('a' + i);
		}
	}
	cout << ans << endl;
	return 0;
}