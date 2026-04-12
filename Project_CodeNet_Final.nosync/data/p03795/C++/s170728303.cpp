#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
#define forn(a, n) for(int a = 0; a<(int) (n); ++a)
#define rforn(a, n) for(int a = (n)-1; a>=0; --a)
using namespace std;
const int N = 6e5+20;

int main()
{
    int n, m, b;
    cin>>n;
    m = n;
    b=0;
    while(m>=15)
    {
        m-=15;
        b++;
    }
    cout<<n*800-(200*b)<<endl;

}