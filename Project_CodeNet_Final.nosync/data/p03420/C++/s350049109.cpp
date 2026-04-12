#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define MOD 1000000007
#define NUM 2520
#define INF (1LL<<50)
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)


void func(long long N, long long K){
    lli sum = 0;
    if(K==0){
        cout<<N*N<<endl;
        return;
    }
    for(lli i=K+1;i<=N;i++){
        lli a = (i-K)*(N/i);
        sum += (a+ max(0LL,N%i-K+1));
    }
    cout<<sum<<endl;
}

int main(){
    // cout << fixed << setprecision(5);

    long long N;
    scanf("%lld",&N);
    long long K;
    scanf("%lld",&K);
    func(N, K);
    return 0;
}
