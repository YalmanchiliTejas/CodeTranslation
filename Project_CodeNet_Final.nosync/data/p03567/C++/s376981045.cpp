#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <time.h>

using namespace std;
typedef long long int ll;

int main()
{
	char s[5];
	scanf("%s", s);
	int n=strlen(s);
	for(int i=0; i<n-1; i++){
		if(s[i]=='A' && s[i+1]=='C'){
			printf("%s\n", "Yes");
			return 0;
		}
	}
	printf("%s\n", "No");
    return 0;
}
