#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main(){
	char s[4];
	cin >> s;
	if (s[0] == s[1] && s[1] == s[2])cout << "No";
	else cout << "Yes";
	return 0;

}