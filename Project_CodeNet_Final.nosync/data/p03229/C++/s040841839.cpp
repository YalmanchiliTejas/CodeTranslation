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
#define pr(num) cout << num << endl
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

ll N;
ll a[100100];
ll ans=0;

void A() {
    ll i;
    
    ans+=a[N/2]-a[N/2-1];
    for(i=0; i<N; i++) {
        if(i==N/2 || i==N/2-1) continue;
        if(i>N/2) ans+=2*a[i];
        else ans-=2*a[i];
    }
}

void B() {
    ll i;
    
    ans-=a[N/2]+a[N/2-1];
    for(i=0; i<N; i++) {
        if(i==N/2 || i==N/2-1) continue;
        if(i>N/2) ans+=2*a[i];
        else ans-=2*a[i];
    }
    
    ll tmp=a[N/2]+a[N/2+1];
    for(i=0; i<N; i++) {
        if(i==N/2 || i==N/2+1) continue;
        if(i>N/2+1) tmp+=2*a[i];
        else tmp-=2*a[i];
    }
    
    ans=max(ans, tmp);
    
}

int main(void) {
    cin >> N;
    ll i;
    
    for(i=0; i<N; i++) {
        cin >> a[i];
    }
    sort(a, a+N);
    
    
    if(N%2==0) {
        A();
    }else {
        B();
    }
    
    pr(ans);
    
    
}
