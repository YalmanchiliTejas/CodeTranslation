#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <sstream>
#include <limits>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <cctype>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <map>
#include <set>
#define PI (acos(-1.0))
#define Abs(a) (((a)<0) ? (-(a)) :(a) )
#define rep(i,n) for((i)=0;(i)<(n);(i)++)
#define Rep(i,n) for(int i=0;i<(n);i++)
#define Rrep(i,n) for(int i=((n)-1);i>=0;i--)
#define rrep(i,n) for((i)=(n)-1;(i)>=0;(i)--)
#define Pii pair<int,int>
#define PB push_back
#define Size(x) ((int)(x.size()))
using namespace std;
typedef long long mint;
typedef unsigned long long umint;
int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("in.txt","r",stdin);
    int n;
    cin >> n;
    mint rmax, rmin, bmax, bmin;
    rmax = bmax = numeric_limits<int>::min();
    rmin = bmin = numeric_limits<int>::max();
    int mnball = 0, mxball = 0;
    vector<pair<mint,mint> > arr(n);
    Rep(i,n)
    {
        cin >> arr[i].first >> arr[i].second;
        if(arr[i].first < arr[i].second)
            swap(arr[i].first, arr[i].second);
        if(arr[i].first > arr[mxball].first)
        {
            mxball = i;
        }
        if(arr[i].second < arr[mnball].second)
        {
            mnball = i;
        }
        rmax = max(arr[i].first, rmax);
        rmin = min(arr[i].first, rmin);
        bmax = max(arr[i].second, bmax);
        bmin = min(arr[i].second ,bmin);
    }
    
    mint ans = (rmax - rmin) * (bmax - bmin);
    
    
    rmin = bmin;
    mint mul = (rmax - rmin);
    if(mxball == mnball)
    {
        cout << ans << endl;
        return 0;
    }
    mint omax = max(arr[mxball].second, arr[mnball].first);
    mint omin = min(arr[mxball].second, arr[mnball].first);
    arr.erase(arr.begin() + max(mxball,mnball));
    arr.erase(arr.begin() + min(mxball,mnball));
    
    multiset<mint> s;
    sort(arr.begin(), arr.end(), greater<pair<mint,mint> > ());
    Rep(i,arr.size())
    {
        s.insert(arr[i].first);
    }
    bmax = numeric_limits<int>::min();
    bmin = numeric_limits<int>::max();
    for(int i = 0; i < arr.size(); i++)
    {
        mint mn = min(omin, *s.begin());
        mint mx = max(omax, arr[i].first);
        ans = min(ans, mul * (mx - mn));
        s.erase(s.find(arr[i].first));
        omin = min(omin, arr[i].second);
        omax = max(omax, arr[i].second);
    }
    cout << ans << endl;
    return 0;
}


