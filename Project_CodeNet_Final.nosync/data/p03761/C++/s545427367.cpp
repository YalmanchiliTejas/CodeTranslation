#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>

#include <bits/stdc++.h>
#include <cmath>
#include <limits>

using namespace std;


int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	map<char, vector<int>> MP;
	for(int i=0; i<N; i++){
		string S;
		cin >> S;
		for(int j=0; j<S.size(); j++){
			char c = S[j];
			if(MP.count(c)==0){
				vector<int> v(N, 0);
				v[i]++;
				MP[c] = v;
			}
			else{
				MP[c][i]++;
			}
		}

	}
	for(auto itr = MP.begin(); itr != MP.end(); itr++){
		char c = itr->first;
		vector<int> v = itr->second;
		sort(v.begin(), v.end());
		int L = v[0];
		for(int i = 0; i < L; i++){
			printf("%c", c);
		}
	}
	printf("\n");
	return 0;
}