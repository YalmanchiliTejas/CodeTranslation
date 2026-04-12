#pragma warning(disable:4996)
//#define _CRT_NONSTDC_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <math.h>
#include <bitset>
#include <fstream>
#include <numeric>
#include <sstream>
#include <algorithm>
#include <string>
#include <cstring>
#include <iomanip>
#include <unordered_map>
#include <ctime>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <deque>


using namespace std;
typedef long long ll;
typedef long double ld;
                        
#define all(x)   (x).begin(), (x).end()           /*sorting STL */
#define fastio	 ios_base::sync_with_stdio(0);  cin.tie(nullptr);  cout.tie(nullptr)

#define TRIPmin(a, b, c) 	min(a, min(b, c))
#define TRIPmax(a, b, c)    max(a, max(b, c))
#define fillchar(a,x) 		memset(a, x, sizeof (a))

//#define mod		(1000000000+7)

/***********************************************************************/

int main() {
    int n;
    cin >> n;
    if(n < 30) cout << "No";
    else cout << "Yes";
    return 0;
}