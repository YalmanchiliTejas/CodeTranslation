#include<bits/stdc++.h>
 
#define INF 1000000007
#define LINF 1000000000000000007
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> P;


string s;

int main(){
	cin >> s;
	
	for(int i = 0; i < s.size()-1; i++){
		if(s[i] == 'A' && s[i+1] == 'C'){
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	
	return 0;
}