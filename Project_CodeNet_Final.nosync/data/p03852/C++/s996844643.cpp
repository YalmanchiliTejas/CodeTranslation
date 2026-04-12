#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
using namespace std;
typedef long long LL;
const int MaxN = 1e5;
const int Inf = 1 << 30;

int main()
{
	char c;
	while(~scanf("%c",&c)){
		if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') printf("vowel\n");
		else if(c >= 'a' && c <= 'z') printf("consonant\n");
	}
    return 0;
}