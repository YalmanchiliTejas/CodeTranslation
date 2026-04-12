#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <climits>
#include <bitset>
#include <list>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main(){
	string s;
	int n, k;
	cin >> n >> s >> k;
	for(int i=0; i<n; i++){
		if(s[i]!=s[k-1]) cout << "*";
		else cout << s[i];
	}
	cout << endl;
	return 0;
}