#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N; cin >> N; 
	if(N % 2){
		cout << "First" << "\n"; return 0; 
	}
	set<int> S[100010]; 
	int D[100010] = {}; 
	for(int i = 0; i < N-1; i++){
		int a, b; cin >> a >> b; 
		a--; b--; 
		S[a].insert(b); S[b].insert(a); 
		D[a] ++; D[b] ++; 
	}
	queue<int> L; 
	for(int i = 0; i < N; i++){
		if(D[i] == 1) L.push(i); 
	}
	bool used[100010] = {}; 
	while(L.size()){
		int p = L.front(); 
		L.pop(); 
		if(used[p]) continue; 
		used[p] = true; 
		int q = *S[p].begin(); 
		if(used[q]){
			cout << "First" << "\n"; return 0; 
		}
		used[q] = true; 
		for(auto it = S[q].begin(); it != S[q].end(); it++){
			S[*it].erase(q); 
			D[*it] --; 
			if(D[*it] == 1) L.push(*it); 
		}
	}
	cout << "Second" << "\n"; 
}