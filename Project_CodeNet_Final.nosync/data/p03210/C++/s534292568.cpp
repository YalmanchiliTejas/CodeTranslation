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

const int MAX = 1024;

int main(void) {
	// in = fopen("A.in", "rt");
	
	int x;
	fscanf(in, "%d", &x);
	if (x == 3 || x == 5 || x == 7) {
	    fprintf(out, "YES\n");
    } else {
	    fprintf(out, "NO\n");
    }
	
	return 0;
}