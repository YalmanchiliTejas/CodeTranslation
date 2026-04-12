#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#define pr(num) printf("%lld\n", num)
#define max(a, b) ((a)>(b) ? (a):(b))
#define min(a, b) ((a)<(b) ? (a):(b))
#define INF 1000000000000000000
#define MOD 1000000007LL
#define MAX 100010
#define BLACK 0
#define WHITE 1
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef map<ll, ll> Map;

int main(void) {
    ll N, X;
    cin >> N >> X;
    ll i;
    ll l[60], b[60], p[60];
    ll ans=0;
    
    l[0]=1;
    b[0]=0;
    p[0]=1;
    for(i=1; i<=50; i++) {
        l[i]=2*l[i-1]+3;
        b[i]=2*b[i-1]+2;
        p[i]=2*p[i-1]+1;
    }
    
    ll len=l[N];
    i=N;
    while(i>=0) {
        if(X<=len/2) {
            len-=3;
            len/=2;
            X--;
            i--;
        }else {
            if(i==0) {
                ans++;
            }else {
                ans+=p[i-1]+1;
            }
            
            len-=3;
            len/=2;
            X-=2;
            X-=l[i-1];
            i--;
        }
    }
    
    pr(ans);
    
}