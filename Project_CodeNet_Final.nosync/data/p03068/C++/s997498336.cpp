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
template<typename T> inline T gcd(T a, T b) { return b ? gcd(b,a%b) : a; }
template<typename T> inline T lcm(T a, T b) { return a / gcd(a,  b) * b; }
inline double isint(double a) { return a>=0 && ceil(a)==floor(a); }

/*-----8<-----8<-----*/


int main(){
    int N,K;
    string S;
    cin >> N >> S >> K;

    string aaa="";
    char r=S[K-1];
    rep(i,S.size()){
        if(r==S[i]){aaa+=S[i];}
        else{aaa+='*';}
    }


    cout << aaa << endl;
    return 0;
}

