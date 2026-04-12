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
#include <stack>
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
//const long long MOD = 998244353;
using namespace std;


int main(int argc, char* argv[])
{
    int n;
    scanf("%d", &n);
    vector<pair<int,int> > z;
    int i;
    for(i=0; i<n; i++) {
        int tmp;
        scanf("%d", &tmp);
        z.push_back(make_pair(tmp,i));
    }
    sort(z.begin(),z.end());

    vector<int> ans(n);
    for(i=0; i<n; i++) {
        if(i<n/2) ans[z[i].second]=z[n/2].first;
        else      ans[z[i].second]=z[n/2-1].first;
    }
    for(i=0; i<n; i++) {
        printf("%d\n", ans[i]);
    }

    return 0;
}

