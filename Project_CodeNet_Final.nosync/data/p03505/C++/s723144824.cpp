#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <iomanip>
#include <functional>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <cmath>
#include <cctype>
#include <cstdio>
#define ll long long
#define INF 1e+9
#define MOD 1000000007
using namespace std;

int main(){
    ll K,A,B;
    cin >> K >> A >> B;
    
    ll ans=1;
    K-=A;
    
    if(A-B<=0){
        if(K<=0){
            cout<<1<<endl;
        }else{
            cout<<-1<<endl;
        }
    }else{
        ans += 2*((K+A-B-1)/(A-B));
        cout<<ans<<endl;
    }

    return 0;
}
