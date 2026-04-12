#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    //vactor<int> H(n);
    int max=0;
    
    int ans = 0,tmp = 0;
    rep(i,n){ 
        cin >> tmp;
        if(max <= tmp){
            max = tmp;
            ans++;
        }
    }
    
    cout << ans << endl;

    return 0;
}