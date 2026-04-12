#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <queue>
#include <climits>

using namespace std;

typedef long long ll;

int t;
string N;

ll compute(int lefti, int len, int k, int maxdigit, bool ismax) 
{
    if(k==0) return 1;
    if(len==0) return 0;
    if(maxdigit == 0) return compute(lefti+1, len-1, k, ismax ? N[lefti+1]-'0':9, ismax);
    ll ans = 0;
    for(int i=1;i<maxdigit;++i)
        ans += compute(lefti+1, len-1, k-1, 9, false);
    ans += compute(lefti+1, len-1, k-1, ismax ? N[lefti+1]-'0' : 9, ismax);
    ans += compute(lefti+1, len-1, k, 9, false);
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout); 
    int k;
    while (cin>>N>>k) {
        ll ans = 0;
        for(int i=1;i<(N[0]-'0');++i) 
            ans += compute(1, N.length()-1, k-1, 9, false);
        ans += compute(1, N.length()-1, k-1, N[1]-'0', true);
        ans += compute(1, N.length()-1, k, 9, false);
        cout<<ans<<endl;
    }
    return 0;
}