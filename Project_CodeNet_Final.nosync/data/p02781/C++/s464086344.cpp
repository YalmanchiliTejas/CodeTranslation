#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 10000000000
#define MOD 1000000007
using ll = long long;
using Graph = vector<vector<int>>;

ll com(ll N, ll R){
        if(R < 0 || R > N) return 0;
        if(R == 1) return N;
        else if(R == 2) return N*(N-1)/2;
        else return N*(N-1)*(N-2)/6;
}

string S;
int N,K;

ll rec(int i, int k, int smaller){//i桁目以降について、0以外の値をK個使用可能、完全に小か否かを考える。
    if(i == N){
        if(k == 0) return 1;
        else return 0;
    }
    if(k == 0) return 1;

    if(smaller) return com(N-i,k)*pow(9,k);
    else{
        if(S[i]=='0')return rec(i+1,k,false);
        else{
            ll zero = rec(i+1,k,true);
            ll aida = rec(i+1,k-1,true)*(S[i]-'1');
            ll same = rec(i+1,k-1,false);
            return zero+aida+same;
        }
    }
}

int main(){
    cin>>S>>K;
    N = S.size();
    cout<<rec(0,K,false)<<endl;
}
