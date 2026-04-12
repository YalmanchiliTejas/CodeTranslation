//agc007_a.cpp
//Sat Nov  3 10:16:50 2018

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
	int h,w;
	cin >> h >> w;

	string s[h+2];
	s[0] += '.';
	s[0] += '#';
	for (int i=2;i<w+2;i++){
		s[0] += '.';
	}

	for (int i=1;i<=h;i++){
		string temp;
		cin >> temp;
		s[i] = '.' + temp + '.';
	}

	for (int i=0;i<w;i++){
		s[h+1] += '.';
	}
	s[h+1] += '#';
	s[h+1] += '.';

	int flag = 1;

	for (int i=1;i<=h;i++){
		for (int j=1;j<=w;j++){
			if (s[i][j] == '#'){
				if ((s[i-1][j] == '#' && s[i][j-1] == '#') ||
					(s[i-1][j] == '.' && s[i][j-1] == '.')
					){
					flag = 0;
				}else if ((s[i+1][j] == '#' && s[i][j+1] == '#') ||
						(s[i+1][j] == '.' && s[i][j+1] == '.')
					){
					flag = 0;
				} 
			}
		}
	}

	if (flag == 1){
		cout << "Possible" << endl;
	}else {
		cout << "Impossible" << endl;
	}
}