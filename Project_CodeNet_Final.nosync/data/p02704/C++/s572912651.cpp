#include <bits/stdc++.h>
using namespace std;
int N; 
bool S[510], T[510]; 
unsigned long long U[510], V[510];
unsigned long long A[510][510]; 
bool ok = true;
void solve(int d){
	unsigned long long B[510][510] = {}; 
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			B[i][j] = 7; 
		}
	}
	bool R[510] = {}; bool C[510] = {}; 
	for(int i = 0; i < N; i++) R[i] = ((U[i] >> d) & 1);
	for(int i = 0; i < N; i++) C[i] = ((V[i] >> d) & 1);
	vector<int> row[4]; vector<int> col[4]; 
	vector<int> Row, Col; // 最後に調整用
	/*	0 は全部 0
		1 は全部 1
		2 は少なくとも1つ 0
		3 は少なくとも1つ 1
	*/
	for(int i = 0; i < N; i++){
		if(S[i] == 0 && R[i] == 0){
			row[2].push_back(i); Row.push_back(i); 
		}
		if(S[i] == 0 && R[i] == 1) row[1].push_back(i); 
		if(S[i] == 1 && R[i] == 0) row[0].push_back(i); 
		if(S[i] == 1 && R[i] == 1){
			row[3].push_back(i); Row.push_back(i); 
		}
	}
	for(int i = 0; i < N; i++){
		if(T[i] == 0 && C[i] == 0){
			col[2].push_back(i); Col.push_back(i);
		}
		if(T[i] == 0 && C[i] == 1) col[1].push_back(i); 
		if(T[i] == 1 && C[i] == 0) col[0].push_back(i); 
		if(T[i] == 1 && C[i] == 1){
			col[3].push_back(i); Col.push_back(i); 
		} 
	}
	if(row[0].size() > 0 && col[1].size() > 0){
		ok = false; return; 
	}
	if(row[1].size() > 0 && col[0].size() > 0){
		ok = false; return; 
	}
	for(auto i : row[0]){
		for(int j = 0; j < N; j++) B[i][j] = 0; 
	}
	for(auto i : row[1]){
		for(int j = 0; j < N; j++) B[i][j] = 1;  
	}
	for(auto i : col[0]){
		for(int j = 0; j < N; j++) B[j][i] = 0; 
	}
	for(auto i : col[1]){
		for(int j = 0; j < N; j++) B[j][i] = 1;  
	}
	int RR = Row.size(); int CC = Col.size(); 
	if(RR > 1 && CC > 1){
		for(int i = 0; i < RR; i++){
			for(int j = 0; j < CC; j++){
				B[Row.at(i)][Col.at(j)] = (i + j) % 2; 
			}
		}
	}else if(RR == 1){
		if(row[0].size() && row[1].size()){
			int k = Row.at(0);
			for(int i = 0; i < N; i++){
				if(B[k][i] == 7) B[k][i] = S[i]; 
			}
		}else if(row[0].size()){
			int k = Row.at(0); 
			for(auto p : Col) B[k][p] = 1; 
			if(col[2].size() > 1){ 
				B[k][col[2].at(0)] = 0; 
			}else if(col[2].size() == 1 && R[k] == 0 && !col[0].size()){
				B[k][col[2].at(0)] = 0; 
			}
		}else if(row[1].size()){
			int k = Row.at(0); 
			for(auto p : Col) B[k][p] = 0; 
			if(col[3].size() > 1){ 
				B[k][col[3].at(0)] = 1; 
			}else if(col[3].size() == 1 && R[k] == 1 && !col[1].size()){
				B[k][col[3].at(0)] = 1; 
			}
		}
	}else if(CC == 1){
		if(col[0].size() && col[1].size()){
			int k = Col.at(0);
			for(int i = 0; i < N; i++){
				if(B[i][k] == 7) B[i][k] = T[i]; 
			}
		}else if(col[0].size()){
			int k = Col.at(0); 
			for(auto p : Row) B[p][k] = 1; 
			if(row[2].size() > 1){ 
				B[row[2].at(0)][k] = 0; 
			}else if(row[2].size() == 1 && C[k] == 0 && !row[0].size()){
				B[row[2].at(0)][k] = 0; 
			}
		}else if(col[1].size()){
			int k = Col.at(0); 
			for(auto p : Row) B[p][k] = 0; 
			if(row[3].size() > 1){ 
				B[row[3].at(0)][k] = 1; 
			}else if(row[3].size() == 1 && C[k] == 1 && !row[1].size()){
				B[row[3].at(0)][k] = 1; 
			}
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			A[i][j] += (B[i][j] << d); 
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0); 
	cin >> N; 
	for(int i = 0; i < N; i++) cin >> S[i]; 
	for(int i = 0; i < N; i++) cin >> T[i]; 
	for(int i = 0; i < N; i++) cin >> U[i]; 
	for(int i = 0; i < N; i++) cin >> V[i]; 
	if(N == 1){
		if(U[0] == V[0]) cout << U[0] << endl; 
		else cout << -1 << endl; 
		return 0; 
	}
	for(int d = 0; d < 64; d++){
		solve(d); 
		if(!ok){
			cout << -1 << endl; return 0; 
		}
	}
	unsigned long long SUMr[510] = {}, PROr[510] = {};
	unsigned long long SUMc[510] = {}, PROc[510] = {};
	for(int i = 0; i < N; i++) PROr[i] = -1; 
	for(int i = 0; i < N; i++) PROc[i] = -1; 	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			SUMr[i] |= A[i][j];
			SUMc[j] |= A[i][j]; 
			PROr[i] &= A[i][j]; 
			PROc[j] &= A[i][j]; 
		}
	}
	for(int i = 0; i < N; i++){
		if(S[i] == 0 && PROr[i] != U[i]) ok = false; 
		if(S[i] == 1 && SUMr[i] != U[i]) ok = false; 
		if(T[i] == 0 && PROc[i] != V[i]) ok = false; 
		if(T[i] == 1 && SUMc[i] != V[i]) ok = false; 
	}
	if(!ok){
		cout << -1 << endl; return 0; 
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << A[i][j] << " "; 
		}
		cout << endl; 
	}
}