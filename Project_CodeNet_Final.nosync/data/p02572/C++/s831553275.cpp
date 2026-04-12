#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef  long long ll;
typedef  unsigned long long ull;

template<typename T>
void fin (T a){
    cout<<a<<endl;
    exit(0);
}

template<typename S>
void print(S a){
    cout<<a<<endl;
}

template<typename U>
void pprint(U a){
    cout<<a;
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ull n;
    cin>>n;
    vector<ull> a(n);
    ull tmp;
    ull sum = 0;
    ull ans = 0;
    ull tmpmod;
    const ull mod =  1000000007;
    rep(i,n){
        cin>>tmp;
        tmpmod = (sum*tmp)%mod;
        ans +=tmpmod;
        ans%=mod;
        sum += tmp;
        sum%=mod;
    }


    fin(ans) ;

    return 0;
}


