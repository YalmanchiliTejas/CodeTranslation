#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) ((int)(x).size())
#define in(x) int x;cin>>x
#define bit(n) (1<<(n))

#define rep(i,n) for (int i=0;i<(n);i++)
#define repp(i,n) for (int i=0;i<=(n);i++)

int main(){
	string c;
	cin >> c;
	if(c == "a" || c == "i" || c == "u" || c == "e" || c == "o")
		cout << "vowel" << endl;
	else
		cout << "consonant" << endl;
	
	return 0;
}
