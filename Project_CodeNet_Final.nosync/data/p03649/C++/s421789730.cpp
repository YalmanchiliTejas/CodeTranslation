#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cassert>
#include <deque>
#include <queue>
#include <map>
#include <set>
#define FOR(j,k,n) for (int j = k; j < (int)(n); j++)
#define MAXN 100000000000000000
#define newl printf("\n")
#define test(t)  int t; cin>>t; for(int tes = 0; tes < t; tes++)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long int lli;
const int MM = 220000;
lli m,n,k,p1,p2,p3,p,f,a[MM];
string s,s1,s2;
set<lli> g[MM];
bool chec()
{
    for (int i=0; i<n; i++) {
        if(a[i] > n-1)
            return 1;
    }
    return 0;
}
lli mpos(lli val)
{
    for (int i=0; i<n; i++) {
        if(a[i] == val)
        {
            return i;
        }
    }
    return 0;
}
int main(){
    fio;
        // Have you solved the problem completely?
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>a[i];
    }
    lli ans = 0;
    
    while (chec()) {
        lli mx = *max_element(a, a+n);
        lli pos = mpos(mx);
        lli red = mx-n+1;
        lli inc = red/n;
        if(red%n > 0)
            inc++;
//        cout<<a[pos]<<" -> ";
        a[pos] -= inc * n;
        for (int i=0; i<n; i++) {
            if(i != pos)
                a[i] += inc;
        }
//        cout<<a[pos]<<endl;
        ans += inc;
//        cout<<inc<<" "<<mx<<" "<<pos<<endl;
//        for (int i=0; i<n; i++) {
//            cout<<a[i]<<" ";
//        }
//        cout<<endl;
    }
    cout<<ans;
    return 0;
}
