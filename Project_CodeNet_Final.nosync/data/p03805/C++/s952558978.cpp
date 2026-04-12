#include <bits/stdc++.h>
#include <algorithm>
#include <string>
using namespace std;
int main() {
int N, M; 
cin >> N >> M; 
int A[10][10] = {}; 
for(int i = 0; i < M; i++){
	int a, b; 
	cin >> a >> b; 
	A[a][b] = 1, A[b][a] = 1; 
}
int B[8] = {1, 2, 3, 4, 5, 6, 7, 8}; 
int count = 0; 
do{
	bool possible = 1; 
	for(int i = 0; i < N-1; i++){
		if(A[B[i]][B[i+1]] == 0){
			possible = 0; 
			break; 
		}
    }
	if(possible){count ++;}
} while (next_permutation(B+1, B+N));
cout << count << endl;
}