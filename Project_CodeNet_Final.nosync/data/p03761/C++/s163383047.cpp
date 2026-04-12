#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <climits>
#include <bitset>
#include <list>
#include <map>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main(){
	int n;
	cin >> n;
	vector<int> cnt(26,99);
	for(int i=0; i<n; i++){
		string s;
		cin >> s;
		vector<int> c(26,0);
		for(int j=0; j<s.length(); j++){
			c[s[j]-'a']++;
		}
		for(int j=0; j<26; j++) cnt[j]=min(cnt[j], c[j]);
	}
	for(int i=0; i<26; i++){
		for(int j=0; j<cnt[i]; j++){
			printf("%c", 'a'+i);
		}
	}
	cout << endl;
	return 0;
}