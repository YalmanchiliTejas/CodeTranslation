#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
	int T;
	while(cin >> T, T){
		vector<int> in;
		int a;
		for(int i = 0; i < T; i++){
			cin >> a;
			in.push_back(a);
		}
		sort(in.begin(), in.end());
		int ans = 0;
		for(int i = 1; i < in.size()-1; i++){
			ans += in[i];
		}
		cout << (int)(ans / (in.size()-2)) << endl;
	}
	
	return 0;
}