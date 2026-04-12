/*
ID: espr1t
TASK: 
KEYWORDS: 
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
FILE* in = stdin; FILE* out = stdout;

const int MAX = 55;

long long size[MAX];
long long patties[MAX];

long long recurse(int level, long long rem) {
    if (rem == 0)
        return 0;
    if (level == 0)
        return 1;
    if (rem >= size[level])
        return patties[level];
    
    long long ans = 0;
    rem--;
    ans += recurse(level - 1, min(size[level - 1], rem));
    rem -= size[level - 1];
    if (rem > 0) {
        ans++;
        rem--;
    }
    if (rem >= 0) {
        ans += recurse(level - 1, min(size[level - 1], rem));
        rem -= size[level - 1];
    }
    
    return ans;
}

int main(void) {
	// in = fopen("D.in", "rt");
	
	size[0] = 1, patties[0] = 1;
	for (int i = 1; i < MAX; i++) {
	    size[i] = 1 + size[i - 1] + 1 + size[i - 1] + 1;
	    patties[i] = patties[i - 1] + 1 + patties[i - 1];
    }
	
	int n;
    long long x;
    fscanf(in, "%d %lld", &n, &x);
    fprintf(out, "%lld\n", recurse(n, x));
	
	return 0;
}