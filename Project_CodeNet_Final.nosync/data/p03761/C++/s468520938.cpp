#include<bits/stdc++.h>
using namespace std;
int main(){

	int n ;
	cin >> n;
	vector< int > A(30 , (1 << 22)) ;
	for(int i = 0 ;i < n ;i ++){
		string s; 
		cin >> s;
		vector< int > B(30);
		for(int l = 0 ;l < s.size() ;l ++)
			B[s[l] - 'a'] ++;
		for(int l = 0; l < 30 ;l ++)
			A[l] = min(A[l] , B[l]);
	}
	string res = "";
	for(int i = 0 ;i < 30 ;i ++){
	
		for(int k = 0 ; k < A[i] ; k ++)
			res += char(i + 'a');
	}
	cout << res << endl;
	
}