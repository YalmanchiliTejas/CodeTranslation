/* 
	Author: ankrypt
*/


#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define u64 unsigned long long int

int A, B;
char arr[105][105];
vector<int> indRow, indCol;
int flag = 0;
int vis[105];
int vis1[105];

int main() {
	scanf("%d %d", &A, &B);
	for(int i = 0; i < A; i++) {
		for(int j = 0; j < B; j++) {
			cin >> arr[i][j];
		}
	}
	for(int i = 0; i < A; i++) {
		flag = 0;
		for(int j = 0; j < B; j++) {
			if(arr[i][j] == '#') {
				flag = 1;
				break;
			}
		}
		if(!flag) {
			indRow.push_back(i);
			vis[i] = 1;
		}
	}
	for(int j = 0; j < B; j++) {
		flag = 0;
		for(int i = 0; i < A; i++) {
			if(arr[i][j] == '#') {
				flag = 1;
				break;
			}
		}
		if(!flag) {
			indCol.push_back(j);
			vis1[j] = 1;
		}
	}
	// for(int i = 0; i < indRow.size(); i++) {
	// 	cout << indRow[i] << " ";
	// }
	// cout << "\n";
	// for(int i = 0; i < indCol.size(); i++) {
	// 	cout << indCol[i] << " ";
	// }
	// cout << "\n";

	// for(int i = 0; i < A; i++) {
	// 	for(int j = 0; j < B; j++) {
	// 		for(int k = 0; k < indRow.size(); k++) {
	// 			for(int z = 0; z < indCol.size(); z++) {
	// 				if(i != indRow[k] && j != indCol[z]) {
	// 					cout << arr[i][j];		
	// 				}
	// 			}
	// 		}
	// 	}
	// 	cout << "\n";
	// }
	for(int i = 0; i < A; i++) {
		flag = 0;
		for(int j = 0; j < B; j++) {
			if(vis[i] != 1 && vis1[j] != 1) {
				cout << arr[i][j];
				flag = 1;
			}
		}
		if(flag) {
			cout << "\n";
		}
	}
	return 0;

}
/*
	Powered by Buggy Plugin
*/
