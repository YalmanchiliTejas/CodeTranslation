#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
#include <fstream>
#define popcount __builtin_popcount
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;

int main()
{
    int n; cin>>n;
    ll s[100010];
    for(int i=0; i<n; i++) cin>>s[i];
    ll ans=0;
    for(int d=1; d<n-1; d++){
        ll sum=0;
        for(int i=1; n-1-(i+1)*d>0; i++){
            if((n-1)%d==0 && n-1<=2*i*d) break;
            sum+=s[i*d];
            sum+=s[n-1-i*d];
            ans=max(ans, sum);
        }
    }
    cout<<ans<<endl;
    return 0;
}