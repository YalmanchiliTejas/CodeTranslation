#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

#define debug(x) cout << '>' << #x << ':' << x << endl;
#define loop(i,n) for(int i=0;i<(n);i++)
#define fori(a,b,i) for(int i=(a);i<=(b);i++)
#define ford(a,b,i) for(int i=(a);i>=(b);i--)
#define fast_io ios_base::sync_with_stdio(false) , cin.tie(NULL);


#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007

#define fir first
#define sec second
#define pb push_back
#define mp make_pair

typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MII;
typedef set<int> SI;
typedef long long int llint;


int main(){
	fast_io;
	int n, m;
    cin>>n>>m;
    if(n == m) cout<<"Yes";
    else cout<<"No";
	return 0;
}
