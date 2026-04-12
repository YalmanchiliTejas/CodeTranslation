#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#define N 105
#define fi(a, b, c) for(int a = (b); a < (c); a++)
#define FI(a, b, c) for(int a = (b); a <= (c); a++)
using namespace std;

char s[N];

int main(){
	scanf("%s", s);
	int n = strlen(s);
	
	fi(i, 0, n - 1){
		if(s[i] == 'A' && s[i + 1] == 'C') {
			puts("Yes");
			return 0;
		}
	}
	
	puts("No");
}