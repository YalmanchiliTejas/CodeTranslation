#include <bits/stdc++.h>
using namespace std;

#define LLINF (1LL<<60)
typedef long long ll;

#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)

template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

template<typename T> inline T divrup(T a, T b) { if (a % b) return a/b+1; else return a/b;}

#define dbg_v1(i,V) do{cout<<"-v1----\n";rep(i,V.size())cout<<" "<<i<<"\t:"<<V[i]<<endl;cout<<endl;}while(0)
#define dbg_v2(i,k,V) do{cout<<"-v2----\n";rep(i,V.size()){rep(k,V[0].size())cout<<" "<<V[i][k];cout<<endl;}}while(0)

//C++14 (GCC 5.4.1)
int main() {
    int A,B,C,X,Y;
    cin >>A>>B>>C>>X>>Y;    
    //-----------------------------------
    int AB=min(X,Y);
    int Adake=X-AB;
    int Bdake=Y-AB;

    ll ans=0;
    ans+=min(A+B,2*C)*AB;
    ans+=min(A,2*C)*Adake;
    ans+=min(B,2*C)*Bdake;

    cout << ans <<endl;
    return (0);
}