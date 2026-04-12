#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<cctype>
#define I insert
#define SG getchar()
using namespace std;
set<char> uoi;
signed main()
{
	uoi.I('a'),uoi.I('e'),uoi.I('i'),uoi.I('o'),uoi.I('u');
	puts(((uoi.count(SG))?("vowel"):("consonant")));
	return 0;
}