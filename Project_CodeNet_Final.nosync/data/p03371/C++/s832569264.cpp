#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <stack>
#include <list>
#include <utility>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <climits>


#define REP(i,N) for(auto i = 0; i <N; i++)
using namespace std;
typedef long long ll;


int in(){
    int temp;
    scanf("%d",&temp);
    return temp;
}

ll lin(){
    ll temp;
    scanf("%lld",&temp);
    return temp;
}



int main() {
    
    ll A = lin();
    ll B = lin();
    ll C = lin();
    ll X = lin();
    ll Y = lin();

    
    ll ans = LONG_MAX;
    
    for(auto i = 0; i<= max(X,Y); i++){
        
        if (ans > 2*C*i + max(0LL,(X-i)*A)  + max(0LL,(Y-i)*B)){
            ans = 2*C*i + max(0LL,(X-i)*A) + max(0LL,(Y-i)*B);
        }
        
    }
    
    cout << ans << endl;
    
    return 0;
}


                          



