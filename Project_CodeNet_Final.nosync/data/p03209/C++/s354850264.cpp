#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;

ll f(ll N, ll X){
        if(X==0) return 0;
        if(X>pow(2,N+2)-3) return pow(2,N+1)-1;
        if(N==0&&X==1) return 1;
        if(X<pow(2,N+1)-1) return f(N-1, X-1);
        if(X==pow(2,N+1)-1) return pow(2,N);
        if(X>pow(2,N+1)-1) return pow(2,N)+f(N-1,X-pow(2,N+1)+1);
}

int main(){
        ll N,X;
        cin >> N >> X;
        cout << f(N,X) << endl;
        return 0;
}