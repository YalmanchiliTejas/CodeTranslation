#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
using namespace std;
typedef long long LL;

char s;
LL c1 = 0,c2 = 0;

int main(){
	for(LL i = 1;i <= 3;i ++){
		cin >> s;
		if(s == 'A') c1 ++;
		else c2 ++;
	}
	if(c1 && c2) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}