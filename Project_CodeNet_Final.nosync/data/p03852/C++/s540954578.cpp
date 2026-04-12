#include <iostream>
#include <unordered_set>

using namespace std;

#define INF 2000000000
#define MOD 1000000007
typedef long long ll;
typedef pair<int, int> P;


int main()
{
	unordered_set<char> vowel;
	vowel.insert('a');
	vowel.insert('i');
	vowel.insert('u');
	vowel.insert('e');
	vowel.insert('o');
	char c;
	cin >> c;

	if (vowel.find(c) != vowel.end()) {
		cout << "vowel" << endl;
	} else {
		cout << "consonant" << endl;
	}

}
