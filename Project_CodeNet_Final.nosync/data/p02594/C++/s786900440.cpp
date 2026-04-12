#include<bits/stdc++.h>
#include <algorithm>
using namespace std;
using ll = long long;
typedef vector<int> vi;
//macros
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int mod = 1e9+7;
void solution(){
	int n;
	cin >> n;
	// int ans = 0;
	if(n >= 30){
		cout << "Yes";
	}
	else{
		cout << "No";
	}
	// cout << ans << endl;
	return;
}

// void solution(){ //read a whole line from the input, possibly containing spaces
// 	string s;
// 	getline(cin,s);
// }
int main(){
	
    fio; // fast input output
    int t;
    t = 1;
    // cin >> t;
    while(t--){
    	// cout << "Case #" << t  << ": ";
        solution();
    }
    return 0;
};