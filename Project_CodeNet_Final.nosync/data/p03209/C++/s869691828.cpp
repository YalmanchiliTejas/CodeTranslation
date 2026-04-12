#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <random>
#include <ctime>
#include <sstream>
#include <numeric>
#include <queue>
using namespace std;

int64_t dp(int n, int64_t x, vector<int64_t> &all, vector<int64_t> &p){
    if (x < 1)
    {
        return 0 ;
    }
    int64_t ans ;
    if (x > all.at(n) -2 )
    {
        ans = p.at(n) ;
    }else if (x > all.at(n-1)+1 )
    {
        ans = dp(n-1, x - all.at(n-1) -2, all ,p) + p.at(n-1) + 1 ;
    }else
    {
        ans = dp(n-1, x-1, all, p) ;
    }
    
    return ans ;
    
    
}

int main(){
    int64_t n ;
    int64_t x ;
    cin >> n >> x;
    vector<int64_t> all(n+1) ;
    vector<int64_t> p(n+1) ;
    all.at(0) = 1 ;
    p.at(0) = 1 ;
    for (size_t i = 1; i < n+1; i++)
    {
        all.at(i) = 2 * all.at(i-1) + 3 ;
        p.at(i) = 2 * p.at(i-1) + 1 ;
    }

    int64_t ans = dp(n, x, all, p) ;
    cout << ans << endl ;
    
}