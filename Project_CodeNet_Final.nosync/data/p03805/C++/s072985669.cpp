#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<tuple>
#include<iomanip>
#define int long 
using namespace std;

signed main() {
	int N,M;
	cin >> N >> M;
	vector<int> graph[10];
	for(int i = 0;i < M;i++) {
		int A,B;
		cin >> A >> B;
		graph[A].push_back(B);
		graph[B].push_back(A);
	}
	if(N == 2) {
		cout << 1 << endl;
	}
	else {
		int count[N];
		for(int i = 0;i < N;i++) {
			count[i] = i + 1;
		}
		int answer = 0;
		do {
			if(count[0] != 1) {
				break;
			}
			else {
				bool A = true;
				for(int i = 1;i < N;i++) {
					bool B = false;
					for(int j = 0;j < graph[count[i - 1]].size();j++) {
						if(count[i] == graph[count[i - 1]].at(j)) {
							B = true;
						}
					}
					if(B == false) {
						A = false;
					}
				}
				if(A == true) {
					answer++;
				}
			}
		} while(next_permutation(count,count + N));
		cout << answer << endl;
	}
}