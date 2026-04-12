#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stdlib.h>
#include <algorithm>
#include <list>
#include <math.h>
#include<string.h>
#define reps(i,j,k) for(int i=(j);i<(k);i++)
#define rep(i,j) reps(i,0,j)

//	rep(i,10)cout << i << endl;
using namespace std;

int main(void){
	string s;
	cin >> s;
	bool flag = false;
	rep(i,s.size()-1){
		if(s[i] == 'A' && s[i+1] == 'C'){
			flag = true;
			cout << "Yes" << endl;
			break;
		}
	}
	if (!flag) cout << "No" <<endl;
	return 0;
}