//Kaori Miyazono, did I reach you ?
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
                        
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	string s;
	cin >> s;
	for(int i = 0; i < s.size() - 1; i++){
		if ( s[i] == 'A' && s[i + 1] == 'C' ){
			cout << "Yes";
			return 0;
		}
	}	
	cout << "No";
	return 0;	
}         




