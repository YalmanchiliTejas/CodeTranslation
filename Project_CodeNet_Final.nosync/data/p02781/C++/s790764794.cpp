//hinagata.cpp
//作成日
//更新日
//目的
//手段
/*includes*/
#include <bits/stdc++.h>
/*namespace*/
using namespace std;
using ll= long long;
/*define macro*/
#define REP(i,n) for(ll i=0;i<(n);i++)
#define REPi(i,a,b) for(ll i=(a);i<(b);i++)
#define REPRi(i,a,b) for(ll i=(a);i>(b);i--)
#define ALL(x) (x).begin(),(x).end()

unsigned choose( unsigned n, unsigned k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    int result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}
int NKmin(string S,int K){
    int size=S.length();
    ll ans=0;
    if(K==1){
        if(size>K){
            ans+=choose(size-1,K)*pow(9,K);
        }
        ans+=(S[0]-'0');
    }else{
        ans+=choose(size-1,K)*pow(9,K);
        ans+=(S[0]-'1')*choose(size-1,K-1)*pow(9,K-1);
        string S1;
        int flag=0;
        REP(i,size-1){
            if(S[i+1]!='0'||flag!=0){
                flag=1;
                S1.push_back(S[i+1]);
            }
        }
        if(!S1.empty()){
        ans+=NKmin(S1,K-1);
        }
    }
    return ans;
}

int main(){
    string S;
    cin>>S;
    int K;
    cin>>K;
    //inputend
    int ans=NKmin(S,K);
    cout<<ans<<endl;
}