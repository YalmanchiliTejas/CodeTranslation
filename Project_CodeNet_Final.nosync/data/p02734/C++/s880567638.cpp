#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#define ll long long

using namespace std;

long long MOD = 998244353;

template<typename T>
void cout_vec(vector<T> &vec){
    for(int i=0; i<vec.size(); i++){
        if (i!=0){
            cout << ' ';
        }
        cout << vec[i];
    }
    cout << endl;
}

int main(){
    int N, S;
    cin >> N >> S;
    vector<ll> A(N,0);
    for(auto &a:A){
        cin >> a;
    }

    vector<ll> dp(S+1,0);
    dp[0]=1;
    ll ans=0;

    for(int i=0; i<N; i++){
        ll a=A[i];
        for(int j=S-a; j>=0; j--){
            if(j==0){
                dp[a]+=(ll) i+1;
                dp[a]%=MOD;
            }else{
                dp[j+a]+=dp[j];
                dp[j+a]%=MOD;
            }
        }
        //cout_vec(dp);
        ans+=dp[S];
        ans%=MOD;
    }
    cout << ans << endl;
}