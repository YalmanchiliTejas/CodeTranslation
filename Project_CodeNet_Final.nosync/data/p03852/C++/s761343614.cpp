#include<iostream>
#include<string>
#include<utility>
#include<cmath>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long int ll;
#define rep(i,n) for(int i=0;i<(int)n;i++)

int main(void) {
	char x; cin >> x;
	if (x == 'a' || x == 'i' || x == 'e' || x == 'u' || x == 'o')
		cout << "vowel" << endl;
	else cout << "consonant" << endl;
	return 0;
}