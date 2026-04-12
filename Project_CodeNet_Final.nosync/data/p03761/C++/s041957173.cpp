#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int f[50][26];
int n;
string s;

int main() {
	// your code goes here
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
	    cin >> s;
	    for(int j = 0; j < s.length(); j++) {
	        f[i][s[j]-'a']++;
	    }
	}
	for(int j = 0; j < 26; j++) {
	    bool can = true;
	    int val = 51;
    	for(int i = 0; i < n; i++) {
    	    can &= (f[i][j] >= 1);
    	    val = min(val,f[i][j]);
    	}
    	if(can) for(int i = 0; i < val; i++) cout << ((char) (j + 'a'));
	}
	cout << endl;
	return 0;
}
