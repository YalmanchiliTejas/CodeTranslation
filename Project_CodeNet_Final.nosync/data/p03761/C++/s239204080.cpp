#include <iostream>
#include <string>

using namespace std;

int main(){
	int n;
	string S[50];
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> S[i];
	}
	
	int cnt[26];
	int min[26];
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 26; j++){
			cnt[j] = 0;
		}
		for(int c = 0; c < S[i].size(); c++){
			cnt[S[i][c] - 'a' + 0]++;
		}
		for(int j = 0; j < 26; j++){
			if(i == 0){
				min[j] = cnt[j];
			}
			else if(min[j] >= cnt[j]){
				min[j] = cnt[j];
			}
		}
	}
	
	for(int j = 0; j < 26; j++){
		for(int i = 0; i < min[j]; i++){
			char ans = j + 'a';
			cout << ans;
		}
	}

	cout << endl;
	
	return 0;
}