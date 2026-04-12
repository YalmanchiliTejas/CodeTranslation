#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const long long INF=INT_MAX/4;
const long long MOD=998244353;
const double EPS=1e-14;
const bool DEBUG=false;

const string YES = "YES";
const string NO = "NO";
const string Yes = "Yes";
const string No = "No";

template<class T>
void debug(T head){
    if(DEBUG){
        cout<<head<<endl;
    }
}

template <class Head, class... Body>
void debug(Head head, Body... body){
    if(DEBUG){
        cout<<head<<" ";
        debug(body...);
    }
}

/////
void answer(ll N, ll K){
    ll answer = 0;
    if(K == 0){
        cout<<N*N<<endl;
        return;
    }

    for(int b=K+1; b<=N; ++b){
        ll t = N / b;
        debug(b, t, b-K);
        answer += t * (b - K);
        answer += max(0ll, (N % b) - (K - 1));
    }
    cout<<answer<<endl;

    return;
}

/////

int main(int argc, char* argv[]){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout.precision(16);

    ll N, K;
    cin>>N>>K;
    answer(N, K);

    return 0;
}
