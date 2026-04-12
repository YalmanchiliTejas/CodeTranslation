#include<iostream>
#include<vector>
#include<string>
#include<array>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<numeric>
#include<iomanip>
#include<utility>
#include<cstdlib>
#include<typeinfo>
#include<stack>
#include<cassert>
#include<functional>
#define int long long int
#define double long double
using namespace std;
#define INT_MAX 1000000007
#define INF 1000000000000000007
const int MAX_N = 1 << 17;
#define REP(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;

signed main()
{
int n;
std::cin >> n;
if(n == 3 || n == 5 || n == 7){
    std::cout << "YES" << std::endl;
} else {
    cout << "NO" << std::endl;
}
return 0;
}