#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;


long long solve(long long N, long long X){
    if(X==0) return 0;
    else if(X==1 && N==0) return 1;
    else if(X==0) return 0;
    else if(X<(1ll << (N+1)) -1)        return solve(N-1,X-1);
    else if(X == (1ll << (N+1))-1)      return 1ll << N;
    else if( (X<(1ll << (N+2)) -3) && (X>(1ll << (N+1))-1))        return (1ll << N)+solve(N-1,X-(1ll<<(N+1))+1);
    else return (1ll << (N+1))-1;
}



int main ()
{
    long long N,X;
    cin >> N >> X;
    cout << solve(N,X) << endl;
    return 0;
}






