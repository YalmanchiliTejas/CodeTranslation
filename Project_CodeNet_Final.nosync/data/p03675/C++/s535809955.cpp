#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#define INT long long
#define MOD 1000000007
#define oo 987654321ll
#define FOR(i,a,b) for(int (i)=a;(i)<(b);(i++))
using namespace std;

int n, s[200020], a[200020], l, r;

int main()
{
    cin.sync_with_stdio(0);
    cin>>n;
    l = 0, r = n-1;
    for(int i = 0 ; i < n ; i++ ) cin>>s[i];
    
    for(int i = n-1 ; i >= 0 ; i-- )
    {
        if( (n-1-i)%2 == (n-1)%2 ) a[l++] = s[i];
        else a[r--] = s[i];
    }
    if( n%2 == 0 ) for(int i = n-1 ; i >= 0 ; i-- ) cout<<a[i]<<" ";
    else for(int i = 0 ; i < n ; i++ ) cout<<a[i]<<" "; cout<<endl;
    return 0;
}
