#include <bits/stdc++.h>
using namespace std;

int main(){
 	int n;
	cin >>n;
	vector<string> a(n);
	vector<int> v(n*26);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		
		for(char s : a[i]) {
			if(s >= 'a' && s <= 'z')
				v[i*26+(s-'a')]++;
		}
	}
	for(int i = 0; i < 26; i++) {
		int min = 50;
		for(int j = 0; j < n; j++) {
			if(min > v[j*26+i])
				min = v[j*26+i];
		}
		v[i] = min;
	}
	for(int i = 0; i<26;i++)
		for(int j = 0; j < v[i]; j++)
			cout << (char)('a'+i);
	cout << endl;
	
}