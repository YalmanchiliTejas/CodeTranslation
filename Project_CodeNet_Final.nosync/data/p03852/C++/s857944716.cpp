#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define REP(i, n) for(int i=0; i<(n); i++)
#define FOR(i, a, n) for(int i=0; i<(n); i++)

int main(){
  	char s;cin >> s;
  	string ans = s == 'a' || s == 'i' || s == 'u' || s == 'e' || s == 'o' ? "vowel" : "consonant";
  	cout << ans << endl;
	return 0;
}