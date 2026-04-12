#include <bits/stdc++.h>
#include<math.h>
#include<algorithm> 
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
using PL = pair<ll , ll> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18
#define mod 1000000007

int main(){
    int n ;
    cin >> n ;
    vector<int> a (n) ;
    deque<int> deq(n, 1e9 + 10) ;
    rep(i, n) cin >> a[i] ;
    rep(i, n){
        if(a[i] <= deq[0]){
            deq.push_front(a[i]) ;
        }
        else {
            int k = lower_bound(deq.begin(), deq.end(), a[i]) - deq.begin();
            deq[k - 1] = a[i] ;
        }
    }
    int ans = 0 ;
    rep(i, n){
        if(deq[i] == 1e9 + 10) break ;
        ans++ ;
    }
    cout << ans << endl ;
} 