#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
#define p(var)  std::cout<<var<<std::endl
#define pp(var) std::cout<<#var" = "<<var<<std::endl
#define PI (acos(-1))
#define rep(i, n)   for (int i = 0; i <  (n); i++)
#define repeq(i, n) for (int i = 1; i <= (n); i++)
#define all(a) (a).begin(), (a).end()
#define pb push_back
using ll = long long;
template<typename T> inline T gcd(T a, T b) { return b ? gcd(b,a%b) : a;}
template<typename T> inline T lcm(T a, T b) { return a / gcd(a,  b) * b;}

/*-----8<-----8<-----*/

int main(){
    int N;
    cin >> N;
    vector<int> h(N,0);
    rep(i,N)cin >> h[i];

    int count=0;
    rep(i,N){
        bool cansee=true;
        rep(j,i){
            if(h[i]<h[j]){cansee=false;break;}
        }
        if(cansee)count++;
    }

    p(count);
    
    return 0;
    
}




