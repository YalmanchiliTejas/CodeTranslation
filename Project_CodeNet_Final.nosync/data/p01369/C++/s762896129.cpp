#include <iostream>
#include <string>
#include <set>
#define llint long long

using namespace std;

string s;
string t = "qwertasdfgzxcvb";
bool used[26];

int main(void)
{
	for(int i = 0; i < t.size(); i++) used[t[i]-'a'] = true;
	
	while(1){
		cin >> s;
		if(s == "#") break;
		
		llint ans = 0;
		for(int i = 1; i < s.size(); i++){
			if(used[s[i]-'a'] != used[s[i-1]-'a']) ans++;
		}
		cout << ans << endl;
	}
	
	return 0;
}
