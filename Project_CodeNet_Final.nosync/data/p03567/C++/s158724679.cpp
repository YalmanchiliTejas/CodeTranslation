#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MEM(a,b) memset(a,b,sizeof(a))
#define MP(a,b) make_pair(a,b)
#define PB push_back
#define lp (p << 1)
#define rp (p << 1|1)

typedef long long ll;
typedef pair<int,int> pii;
const double eps = 1e-8;
const int INF = (1 << 30) - 1;
const int mod = (int)(1e9 + 7);

char s[10];

int main(){
	scanf("%s",s + 1);
	bool flag = false;
	for(int i = 1; s[i + 1] != '\0'; ++i){
		if(s[i] == 'A' && s[i + 1] == 'C'){
			flag = true;
			break;
		}
	}
	if(flag) printf("Yes\n");
	else printf("No\n");
	return 0;
}