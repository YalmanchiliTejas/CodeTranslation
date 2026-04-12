#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>
#include <cstdlib>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long lint;


int main(){
	string s;
	cin >> s;
	if(s[0]==s[1] && s[1]==s[2]) cout <<"No\n";
	else cout<<"Yes\n";
}