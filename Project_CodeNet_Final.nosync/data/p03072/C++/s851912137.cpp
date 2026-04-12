#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)

//C++14 (GCC 5.4.1)
int main() {
    int N;
    cin >>N;

    vector<int> A(N);
    rep(i,N) cin >> A.at(i);
    
    //-----------------------------------
    int ans=0,max=0;
    rep(i,N) if(max<=A[i]){
        ans++;
        max=A[i];
    }

    cout << ans <<endl;
    return (0);
}