//cod2017_qualC_a.cpp
//Sat Oct 20 22:39:02 2018

#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#define INTINF 2147483647
#define LLINF 9223372036854775807
using namespace std;
using ll=long long;
typedef pair<int,int> P;

int main(){
	string s;
	cin >> s;

	int flag = 0;
	for (int i=0;i<s.size()-1;i++){
		if (s[i] == 'A' && s[i+1] == 'C'){
			flag = 1;
		}
	}

	if (flag == 1){
		cout << "Yes" << endl;
	}else {
		cout << "No" << endl;
	}
}