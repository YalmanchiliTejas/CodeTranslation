#include <bits/stdc++.h>
#define s second
#define f first
#define pb push_back
#define endl '\n'
using namespace std;


typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	char c;
	cin >> c;

	bool ans = 0;

	ans |= (c == 'a');
	ans |= (c == 'e');
	ans |= (c == 'i');
	ans |= (c == 'o');
	ans |= (c == 'u');

	cout << (ans ? "vowel" : "consonant") << endl;

	return 0;
}
