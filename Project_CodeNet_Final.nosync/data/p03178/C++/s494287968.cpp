#include<bits/stdc++.h>
#define int long long
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

template<int mod> class modint
{   
private:
    int val;
public:
    int value(){ return val; }
    modint(int x=0){ val=x%mod; }
    modint pow(int n){
        modint res(1),x(val);
        while(n>0){ if(n&1) res*=x; x*=x; n>>=1; }
        return res;
    }
    modint inv(){ return pow(mod-2); }
    modint& operator+=(modint rhs){ val+=rhs.val; if(val>=mod) val-=mod; return *this; }
    modint& operator-=(modint rhs){ val+=mod-rhs.val; if(val>=mod) val-=mod; return *this; }
    modint& operator*=(modint rhs){ val=val*rhs.val%mod; return *this; }
    modint& operator/=(modint rhs){ *this*=rhs.inv(); return *this; }
    modint operator+(modint rhs){ return modint(val)+=rhs; }
    modint operator-(modint rhs){ return modint(val)-=rhs; }
    modint operator*(modint rhs){ return modint(val)*=rhs; }
    modint operator/(modint rhs){ return modint(val)/=rhs; }
};

using mint=modint<1000000007>;
mint dp[100010][2][100];

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s; cin>>s;
    int D; cin>>D;
    int N=s.size();

    dp[0][0][0]=1;
    for(int i=0;i<N;i++) for(int j=0;j<2;j++) for(int k=0;k<D;k++){
        if(j==0){
            for(int d=0;d<=s[i]-'0';d++){
                dp[i+1][d<(s[i]-'0')][(k+d)%D]+=dp[i][j][k];
            }
        }else{
            for(int d=0;d<=9;d++){
                dp[i+1][j][(k+d)%D]+=dp[i][j][k];
            }
        }
    }
    mint ans=dp[N][0][0]+dp[N][1][0]-1;
    cout<<ans.value()<<endl;
    return 0;
}