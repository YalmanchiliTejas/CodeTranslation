#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	int n;
	string s[50];
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> s[i];
	}
	string ans;
	for(char c='a'; c <='z'; c++){
		int min_n = 60;
		for(int i=0; i<n; i++){
			int cnt=0;
			for(int k=0; k<s[i].length(); k++){
				if(s[i][k]==c)cnt++;
			}
			min_n = min(min_n,cnt);
		}
		for(int p=0; p<min_n; p++){
			ans += c;
		}
	}
	cout << ans << endl;
}


