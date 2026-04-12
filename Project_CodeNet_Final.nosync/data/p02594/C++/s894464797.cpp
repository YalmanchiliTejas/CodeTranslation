#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#include <fstream>

using namespace std;

const int DIV = 1000000007;

void solve(int test, istream &in) {
    int x;
    in >> x;
    printf("%s", x >= 30 ? "Yes" : "No");
}

int main(int argc, char* argv[])
{
#ifdef VLAD_LOCAL
	//FILE *f = fopen("in.txt", "r");
    ifstream f("in.txt");
#else
	//FILE *f = stdin;
    istream &f = cin;
#endif
    int tests = 1;
    //f >> tests;
    for (int test = 0; test < tests; test++) {
        solve(test, f);
    }
	return 0;
}

