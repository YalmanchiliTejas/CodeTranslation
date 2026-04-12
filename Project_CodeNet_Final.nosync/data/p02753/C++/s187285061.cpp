#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <iterator>
#include <cmath>
#include <set>
#include <deque> 
#include <string>


using namespace std;

char s[10];


int main()
{
	scanf("%s\n", s);
	if (s[0] != s[1]) {
		printf("Yes\n");
		return 0;
	}
	if (s[1] != s[2]) {
		printf("Yes\n");
		return 0;
	}
	printf("No\n");
			
	return 0;
}
