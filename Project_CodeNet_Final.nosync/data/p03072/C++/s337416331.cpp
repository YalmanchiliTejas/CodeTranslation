#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cassert>
#include <bitset>
#include <list>
#include <cstdio>
#include <stdio.h>
#include <string.h>
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;
using namespace std;

int main()
{
    int n;
    cin >> n;
    int H[n];
    rep(i,n) cin >> H[i];
    int tmp=0, ans=0;
    rep(i,n)
    {
        if(H[i]>=tmp)
        {
            ans++;
            tmp = H[i];
        }
    }
    cout << ans << endl;
    return 0;
}