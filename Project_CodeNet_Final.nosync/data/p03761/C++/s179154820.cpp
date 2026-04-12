#include <iostream>
#include <algorithm>
#include <vector>

#define rep(i,n) for (int i=0; i < (n); ++i)
using ll = long long ;
using namespace std;
const int INF = 1001001001;

int main() {

    int n ;
    cin >> n ;
    vector<int> a(26) ;
    rep(i,n){
        string s ;
        cin >> s ;
        vector<int> tmp(26) ;
        rep(i,s.size()){
            int idx = (int)s[i] ;
            tmp[idx-97]++ ;
        }
        if(i==0){
        rep(i,a.size()){
            a[i] = tmp[i] ;
        }
        }else{
        rep(i,a.size()){
            a[i] = min(tmp[i],a[i]) ;
        }
        }
    }

    string ans = "" ;
    for(char c='a'; c<='z';c++){
            int idx = (int)c ;
            
        if(a[c-97]>0){
            rep(i,a[c-97]){
                ans+=c ;
            }
        }
    }

    cout << ans << endl ;

    return 0 ;
}
