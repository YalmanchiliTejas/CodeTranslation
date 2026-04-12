#include<iostream>
#include <iomanip>
#include <ios>
#include <vector>
#include <string>
#include <algorithm>
#include <string>
#include<limits>
#include<cstdlib>
#include<functional>
#include<cassert>
#include <cstdio>
#include <stack>
#include <queue>
#define fi(p) for(int i=0;i<(p);i++)
using namespace std;
int N;
int L;
int P;
const int MAX_N = 100000;
const int MAX_W = 100000;


int A[MAX_N+1];
int B[MAX_N+1];

void solve() {
	int H;
	int W;
	cin >> H >> W;
	vector<string> map;
	vector<string> res;
	vector<int> h;
	vector<int> w;
	vector<int> w_delete;
	fi(H) {
		string temp;
		cin >>temp;
		int find = temp.find("#");
		if (find == string::npos) {
			continue;
		}
		else {
			map.push_back(temp);
		}
	}



	fi(W) {
		for (int j = 0; j < map.size(); j++) {
			if (map[j][i] == '.') {
				
				if (j == map.size() - 1) {
					w_delete.push_back(i);
				}
				continue;
			}
			else {
				break;
			}
		}
	}



	if (w_delete.size() != 0) {
		fi(map.size()) {
			for (int j = 0; j < W; j++) {
				for (int k = 0; k < w_delete.size(); k++) {
					if (j == w_delete[k]) {
						break;
					}
					else if (j != w_delete[k] && k == w_delete.size() - 1) {
						cout << map[i][j];
					}
				}
			}
			cout << endl;
		}
	}
	else {
		fi(map.size()) {
			cout << map[i] << endl;
		}
	}
}

int main()
{
	solve();

	int a;//止める用
	cin >> a;
	return 0;
}