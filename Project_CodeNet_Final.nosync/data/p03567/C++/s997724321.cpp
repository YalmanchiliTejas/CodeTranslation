#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main(){
	string S;  
	cin >> S; 
	int L = S.size(); 
	string ans = "No"; 
	for(int i = 0; i < L - 1; i++){
		if(S.at(i) == 'A' && S.at(i+1) == 'C') ans = "Yes"; 
	}
	cout << ans << endl;
}