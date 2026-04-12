#include"bits/stdc++.h"
//#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define print(x) cout<<x<<endl;
typedef long long ll;
const int mod = 1e9 + 7;



int main() {
	string s;
	cin >> s;
	if (s == "a" || s == "i" || s == "u" || s == "e" || s == "o") {
		print("vowel");
	}
	else { print("consonant"); }
	return 0;
}