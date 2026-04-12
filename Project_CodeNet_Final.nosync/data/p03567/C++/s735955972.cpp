/********************************************
 *Author*        :ZZZZone
 *Created Time*  : 日 10/22 19:52:26 2017

*********************************************/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <stack>
using namespace std;
typedef pair<int, int> PII;
typedef long long LL;
typedef unsigned long long ULL;

inline void OPEN(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

char s[10];

int main()
{
	while(~scanf("%s", s + 1)){
		int len =  strlen(s + 1);
		bool flag = false;
		for(int i = 1; i < len; i++){
			if(s[i] == 'A' && s[i + 1] == 'C') flag = true;
		}
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
    return 0;
}
