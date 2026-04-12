#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define mem(a,n) memset(a,sizeof(a),n)
typedef long long ll;
const int mod=1e9+7;
const int N=1e5+5;
const int INF=0x3f3f3f3f;
int main()
{
    int x,y,z;
    while(cin>>x>>y>>z)
    {
        x-=z;
        cout<<x/(y+z)<<endl;
    }
    return 0;
}
