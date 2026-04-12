#include <bits/stdc++.h>
#include<math.h>
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int , int> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18 
         
int main(){
    int n ;
    cin >> n;
    vector<int> a (n) ;
    rep(i, n){
        cin >> a[i] ;
    }
    deque<int> d ; 
    rep(i, n){
        int p = lower_bound(d.begin(), d.end(), a[i]) - d.begin() ;
        if(p == 0){
            d.push_front(a[i]) ;
        }
        else {
            d[p - 1] = a[i] ;
        }
    }
    int ans = d.size() ;
    cout << ans << endl ;
}