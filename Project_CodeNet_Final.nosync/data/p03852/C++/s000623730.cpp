#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include "bits/stdc++.h"

typedef long long ll;
using namespace std;

#define FOR(i,n) for(ll i=0;i<n;i++) 
#define RFOR(i,n) for(ll i=n-1;i>=0;--i)
#define COUT(str) cout << str << endl

//宣言　
	string A = "vowel" ;
	string B = "consonant";
	
//入力
	char c ;


int main() {

	cin >> c;

	if(c == 'a'|| c == 'i' || c == 'u' || c == 'e' || c == 'o') COUT(A);
	
	else COUT(B);

	return 0;
}
