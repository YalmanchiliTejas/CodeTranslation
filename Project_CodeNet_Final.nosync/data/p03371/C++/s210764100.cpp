#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
int main(int argc, char *argv[]) {
    int a,b,c,x,y;
    scanf("%d%d%d%d%d", &a,&b,&c,&x,&y);
    int combine = x > y ? y : x;
    int comb_cst = (a+b) < (2*c) ? (a+b) : (2*c);
    int cst = combine * comb_cst;
    if (combine == x ){
        int t = 2*c > b ? b : 2*c;
        cst+= (y-combine) * t;
    }
    else {
        int t = 2*c > a ? a : 2*c;
        cst += (x - combine) * t;
    }
    printf("%d\n", cst);
    return 0;
}