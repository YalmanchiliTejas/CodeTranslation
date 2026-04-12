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
#include <list>
#include <iterator>
#include <assert.h>
#pragma warning(disable:4996) 
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF 9223300000000000000
#define INF 2140000000
const long long MOD = 1000000007;
using namespace std;


int main(int argc, char* argv[])
{
    int n;
    scanf("%d", &n);

    vector<int> a(n);
    int i;
    for(i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }

    set<pair<int,int> > z;
    for(i=0; i<n; i++) {
        auto it = z.lower_bound( make_pair(a[i],-i) );
        if(it==z.begin()) {
            z.insert( make_pair(a[i],-i) );
        }
        else {
            it--;
            z.erase(it);
            z.insert(make_pair(a[i],-i));
        }
    }
    printf("%d\n", (int)z.size());

    return 0;
}

