#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;

int main() {
	const string vowel = "aiueo";
	char character;
	cin >> character;

	if ( vowel.find(character) != string::npos){
        cout << "vowel" << endl;
    } else {
        cout << "consonant" << endl;
    }
}