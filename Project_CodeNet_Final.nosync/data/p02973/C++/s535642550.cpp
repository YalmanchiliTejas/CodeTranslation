#include <bits/stdc++.h>
#include <algorithm>
#include <set>
using namespace std;
int main() {
	int N; cin >> N; 
	int A[100010] = {}; 
	for(int i = 0; i < N; i++) cin >> A[i]; 
	multiset<int> S;
	S.insert(-1145141919); S.insert(1145141919); 
	S.insert(A[0]); 
	for(int i = 1; i < N; i++){
		auto it = S.lower_bound(A[i]); 
		it--; 
		if(*it == -1145141919) S.insert(A[i]); 
		else{
			S.insert(A[i]); S.erase(it); 
		}
	}
	cout << (int) S.size() - 2 << endl; 
}