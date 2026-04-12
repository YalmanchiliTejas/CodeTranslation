#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cassert>
#include <iomanip>
#include <vector>
#include <cstdio>
#include <float.h>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <stack>
#include <functional>
 
using namespace std;
 
#define endl '\n'
#define MOD 1000000007
#define INF 1ll<<30
#define MAX 100010
#define eps 1e-11
#define bit_max 1ll<<32
#define _USE_MATH_DEFINES

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    
    int n;
    cin>>n;
    int mx = 0;
    int ans =0;
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        if(t>=mx)
        {
            ans++;
            mx=  max(t,mx);
        }
    }
    cout<<ans;
    return 0;
}