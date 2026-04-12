#include "bits/stdc++.h"
using namespace std;
using ll = long long;

template <typename TYPE>
void print_vec(const vector<TYPE>& v){
	for(int i=0; i<v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

template <typename TYPE>
void print_vec2(const vector<vector<TYPE>>& v){
  cout << endl; cout << "       ";
  for(int i=0; i<v[0].size(); i++) cout << i << "   "; 
  cout << endl;
	for(int i=0; i<v.size(); i++){
		cout << "i=" << i << ":   ";
		for(int j=0; j<v[i].size(); j++){
			if(v[i][j] == 0) cout << "\x1B[0m" << v[i][j] << "   ";
      else cout << "\x1B[31m" << v[i][j] << "   ";//https://stackoverrun.com/ja/q/12618775
		}
		cout << "\x1B[0m" << endl;
	}
}



int main(){
	int N;
	cin >> N;
	vector<ll> A(N);
	for(int i=0; i<N; i++) cin >> A[i];

	vector<ll> colors;//colors[i]:色iを使った最大のAを格納
	for(int i=0; i<N; i++){
		// これだとTLEになるので 2分探索しないとダメ
		// bool is_same_color = false;
		// for(int j=0; j<(int)colors.size(); j++){
		// 	if(colors[j] < A[i]){
		// 		colors[j] = A[i];
		// 		is_same_color = true;
		// 		break;
		// 	}
		// }
		// if(is_same_color == false) colors.push_back(A[i]);

		//2分探索
		int l_index=-1, r_index = (int)colors.size();
		while(r_index - l_index > 1){
			int mid = (l_index+r_index)/2;
			if(colors[mid] >= A[i]) l_index = mid;
			else r_index = mid;
		}
		if(r_index == colors.size()) colors.push_back(A[i]);
		else colors[r_index] = A[i];
	
	}
	cout << (int)colors.size() << endl;
	return 0;
}

