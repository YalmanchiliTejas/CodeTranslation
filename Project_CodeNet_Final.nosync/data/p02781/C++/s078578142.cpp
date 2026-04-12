#include <bits/stdc++.h>
 
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pii;
 
#define REP(a,b,c) for(ll (a)=(b);(a)<(c);(a)++)
#define PER(a,b,c) for(ll (a)=(b);(a)>=(c);(a)--)
 
void in(ll &x){ cin >> x; }
void pin(ll &x, ll &y){ cin >> x, y; }


int main(){
    //ll N,M,K,a,b,p,q,x,y,z;
    
    ll dp_up[110][5]={0};
    ll dp_low[110][5]={0};

    string N;
    cin >> N;
    ll K;
    in(K);
    
    ll L = N.size();

    dp_up[0][0]=1;
    REP(i,0,L){
        ll n = N[i] - '0';
        REP(j,0,K+1){
            dp_low[i+1][j]+=dp_low[i][j];
            dp_low[i+1][j+1]+=dp_low[i][j]*9;

            REP(k,0,10){
                if(k==n){
                    if(k==0){
                        dp_up[i+1][j]+=dp_up[i][j];
                    }else{
                        dp_up[i+1][j+1]+=dp_up[i][j];
                    }
                }
                if(k<n){
                    if(k==0){
                        dp_low[i+1][j]+=dp_up[i][j];
                    }else{
                        dp_low[i+1][j+1]+=dp_up[i][j];
                    }
                }
            }
        }
    }
    std::cout << dp_low[L][K] + dp_up[L][K] << std::endl;
    return 0;
}