//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <cstring>
#include <climits>
#include <queue>
#include <algorithm>
#include <utility>
#define INF INT_MAX / 2
using namespace std;

typedef pair<int, int> P;
typedef long long ll;

int main(void) {
	string s1 = "qwertasdfgzxcvb";
	string s2 = "yuiophjklnm";


	string s;
	while(cin >> s,s!="#"){
	bool l = false;
	if(s1.find(s[0]) != string::npos)l=true;
	int cnt = 0;
	for(int i=0;i<s.size();i++){
		if(s1.find(s[i]) != string::npos){
			if(!l)cnt++;
			l = true;
		}else{
			if(l)cnt++;
			l = false;
		}
	}
	cout << cnt << endl;
}
}

// command shift d duplicate
// command ctrl 上下
// command D
// command caps G → '' ""
// vector<vector<int>> a(N,vector<int>(M,-1));