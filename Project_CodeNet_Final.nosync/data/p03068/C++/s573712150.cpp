#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>
#include <cstdlib>
using namespace std;
#define REP(i,n) for(int i = 0;i < (int)(n);i++)

int main() {
	vector<char> s;char buf,ast;
	int n,k;
	cin >> n;
	REP(i,n){
		cin >> buf;
		s.push_back(buf);
	}
	cin >> k;
	ast = s[k-1];
	REP(i,n){
		if(s[i]!=ast){
			s[i] = '*';
		}
	}
	REP(i,n){
		cout << s[i];
	}
	return(0);
}
