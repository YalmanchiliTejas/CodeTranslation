#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>
#include <cassert>
#include <stack>
using namespace std;
typedef long long LL;
const int N = 1e6+7 , INF = 0x3f3f3f3f , MOD = 1e9+7;
const double PI = acos(0.0) * 2;
template<typename T1>
T1 gcd(T1 a , T1 b){ return b ? gcd(b,a%b) : a;}

int main(){
#ifdef LOCAL
    freopen("F:\\c++\\in.txt", "r", stdin);
//  freopen("F:\\c++\\out.txt","w",stdout);
#endif
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    puts((a*100+b*10+c)%4==0?"YES":"NO");
    return 0;
}
