#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define INT long long
#define oo 9876543210000000LL
using namespace std;

int h, w;
string m[10];
bool done()
{
    for(int i = 0 ; i < h ; i++ )for(int j = 0 ; j < w ; j++ )
        if( m[i][j] == '#' ) return false;
    return true;
}

bool go(int x, int y)
{
    m[x][y] = '.';
    if( x == h-1 and y == w-1 ) return done();
    bool ret = false;
    if( x+1 < h and m[x+1][y] == '#' ) ret = go(x+1, y);
    if( y+1 < w and m[x][y+1] == '#' ) ret |= go(x, y+1);
    m[x][y] = '#';
    return ret;
}

int main()
{
    cin>>h>>w;
    for(int i = 0 ; i < h ; i++ )
        cin>>m[i], m[i]+=".";
    cout<<(go(0, 0)?"Possible":"Impossible")<<endl;
    return 0;
}
