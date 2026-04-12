#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>

using namespace std;

#include <iostream>
//#include <fstream>

//ifstream cin ("input.in");
//ofstream cout ("output.out");

//ifstream cin (".in")
//ofstream cout (".out");

string s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, k;
	cin>>n;
	cin>>s;
	cin>>k;

	char neededChar = s[k-1];
	for ( int i = 0; i < n; ++i ) {
		if ( s[i] == neededChar ) continue;
		s[i] = '*';
	}

	cout<<s<<'\n';
}