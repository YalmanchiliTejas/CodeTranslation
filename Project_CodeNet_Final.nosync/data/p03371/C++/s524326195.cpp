#include <bits/stdc++.h>

using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using ld = long double;
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define rep3(i, n) for (int i = 1; i < (int)(n+1); i++)
#define rep4(i, s, n) for (int i = (s); i < (int)(n+1); i++)
#define repr(i,n) for (int i = (n-1); i>=0;i--)
#define repr3(i,n) for(int i = (n);i>0;i--)
#define stlen(s) ll s.size()-1
#define all(v) v.begin(), v.end()
#define cout(n) cout<<std::fixed<<std::setprecision(n)
using Graph = vector<vector<int>>;
const ll INF = 1001001000100010;
const ld PI = 3.14159265358979323846;


int main() {
int A,B,C,X,Y,Z=0;
cin>>A>>B>>C>>X>>Y;
if((A+B)<=2*C){
    cout<<A*X+B*Y<<endl;
    
}
else{
    while((X>=1)&&(Y>=1)){
        X--;Y--;Z+=2;
    }
    if((A>2*C)&&(X>0)){
        while(X>0){
            X--;Y--;Z+=2;
        }
    }
    if((B>2*C)&&(Y>0)){
        while(Y>0){
            X--;Y--;Z+=2;
        }
    }
    cout<<A*max(0,X)+B*max(0,Y)+C*Z<<endl;
}
return 0;
}

