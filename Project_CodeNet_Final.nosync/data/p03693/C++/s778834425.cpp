#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF = numeric_limits<long long>::max();
#define intf int_fast64_t
int main(){
    intf r,g,b;
    cin >>r >> g>>b;

    if((g*10+b)%4==0){
        cout << "YES" <<endl;
    }else{
        cout << "NO" <<endl;
    }
}