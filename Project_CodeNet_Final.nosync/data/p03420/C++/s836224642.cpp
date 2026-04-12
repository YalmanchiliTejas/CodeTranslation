#include <bits/stdc++.h>
#include <time.h>
#define l(x) 2*x
#define r(x) (2*x+1)
using namespace std;
typedef long long LL;
const int NMAX = 300505;
const LL llinf = 1e18;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};

int N, K;

int main(){
    cin>>N>>K;
    if(K == 0){
        cout<<(1LL*N*N)<<"\n";
        return 0;
    }
    LL rs =0;
    for(int i=K+1; i<=N; ++i){
        int md = i;
        int chn = md - K;
        rs += chn * ((N+1)/md);
        int other = N+1 - md*((N+1)/md);
        rs += max(0, other-K);
        //cout<<md<<" "<<((N+1)/md)<<" "<<other<<"\n";
    }
    cout<<rs<<"\n";


    return 0;
}
