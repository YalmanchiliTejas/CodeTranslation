#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
	int n;
	cin >> n;
	string str;
	int maxi[26] = {0};
	int count[26];
	for(int i = 0;i < 1;i++){
		cin >> str;
		for(int j = 0;j < 26;j++) count[j] = 0;
		for(int j = 0;j < str.length();j++){
			int c = str[j] - 'a';
			count[c]++;
		}
		for(int j = 0;j < 26;j++){
			maxi[j] = count[j];
		}
	}
	for(int i = 1;i < n;i++){
		cin >> str;
		for(int j = 0;j < 26;j++) count[j] = 0;
		for(int j = 0;j < str.length();j++){
			int c = str[j] - 'a';
			count[c]++;
		}
		for(int j = 0;j < 26;j++){
			if(count[j] < maxi[j]) maxi[j] = count[j];
		}
	}
	str = "";char al = 'a';
	for(int i = 0;i < 26;i++){
		for(int j = 0;j < maxi[i];j++){
			str = str+al;
		}
		al++;
	}
	cout << str << endl;
}
