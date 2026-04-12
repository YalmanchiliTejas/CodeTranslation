#include<cstdio>
#include <iostream>
#include<sstream>
#include<fstream>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<complex>
#include <cstring>
#include<vector>
#include<list>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<bitset>
#include<numeric>
#include<limits>
#include<climits>
#include<cfloat>
#include<functional>
#include<iterator>
#include <random>
#define inf  1000000000
#define mod  1073741824
#pragma GCC optimization ("O3")
using namespace std;
const int N = 100*1000+5;
#define all(x) begin(x),end(x)
int main()
{
   
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    if(n == m)
        cout << "Yes\n"; 
    else
        cout << "No\n";
    return 0;
}
