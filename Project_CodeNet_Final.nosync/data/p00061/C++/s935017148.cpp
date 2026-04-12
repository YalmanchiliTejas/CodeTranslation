#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <bitset>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#define X first
#define Y second
using namespace std;

int main(){
	vector<vector<int> > table(31, vector<int>(0, 0));
	map<int, int> key;
	int num, ac;
	while(scanf("%d,%d", &num, &ac)){
		if(num==0&&ac==0)break;
		table[ac].push_back(num);
		key[num] = ac;
	}
	int n;
	while(cin >> n){
		if(cin.eof()) break;
		int count = 0;
		for(int i = 30; i >= key[n]; i--){
			if(table[i].size()) count++;
		}
		cout << count << endl;
	}
	return 0;
}