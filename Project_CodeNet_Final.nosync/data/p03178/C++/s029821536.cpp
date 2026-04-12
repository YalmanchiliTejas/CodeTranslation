#include<bits/stdc++.h>
using namespace std;

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}


typedef long long ll;

string K;

int D;
const ll mod = 1e9+7;

ll DP[2][100][10000];

ll sum(ll a, ll b){

    ll rta = a+b;
    return a+b>=mod ? rta-mod : rta;
}

int sub(int a, int b){
    a = a%D; b = b%D;
    int rta = a-b+D;
    return rta>=D ? rta-D : rta;
}

ll dp(int l, int m, int i){
    if(i==K.size()) return m==0;
    if(DP[l][m][i]!=-1) return DP[l][m][i];
    ll rta = 0;

    if(l){
        for(int j = 0; j<K[i]-'0'; ++j){
            rta=sum(rta, dp(0, sub(m, j), i+1));
        }
        rta=sum(rta, dp(1, sub(m, K[i]-'0'), i+1));
    }
    else{
        for(int j = 0; j<10; ++j){
            rta=sum(rta, dp(0, sub(m, j), i+1));
        }
    }

    return DP[l][m][i] = rta;
}

int main(){
    memset(DP, -1, sizeof(DP));
    cin>>K>>D;
    ll rta = dp(1,0, 0)-1;
    if(rta<0) rta+=mod;
    cout<<rta<<"\n";
}
