#include <stdio.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <iterator>
#pragma warning(disable:4996)
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF 9223300000000000000
#define INF 2140000000
#define MOD 1000000007
using namespace std;


int main(int argc, char* argv[])
{
    char str[4]={0};
    scanf("%s", str);

    if(str[0]=='a' || str[0]=='i' || str[0]=='u' || str[0]=='e' || str[0]=='o') {
        printf("vowel\n");
    }
    else {
        printf("consonant\n");
    }


    return 0;
}

