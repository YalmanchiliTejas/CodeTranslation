#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{	
 	//freopen("in.txt","r",stdin);
 	//freopen("out.txt","w",stdout);
    int n;
    scanf("%d", &n);
    int x = n / 15 * 200;
    printf("%d\n", n * 800 - x);
 	return 0;
}