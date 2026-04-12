#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <cmath>
#include <cctype>
#include <stack>
#include <map>
#include <cstring>
#include <sstream>
#include <set>
#include <list>
#include <fstream>
#include <iomanip>
#include <assert.h>

#define ll long long
#define ull unsigned long long
#define pii std::pair<int, int>
#define op                            \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(0);

const int INF = 0x3f3f3f3f;
const int maxn = (100000 + 5);
const int mod = (1000000007);

int main()
{
    op
    std::string s;
    std::cin>>s;
    int a=0,b=0;
    for(int i=0;i<3;i++)
        if(s[i]=='A')
            a++;
        else b++;
    if(a==3||b==3)
        std::cout<<"No\n";
    else std::cout<<"Yes\n";
    return 0;
}