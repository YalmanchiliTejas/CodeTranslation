#include <bits/stdc++.h>
using namespace std;

long long calP(long long n,long long x,vector<long long> w,vector<long long> p){
    if(n==0){
        if(x<=0)return 0;
        return 1;
    }
    if(x <= 1+w[n-1])return calP(n-1,x-1,w,p);
    return p[n-1]+1+calP(n-1,x-2-w[n-1],w,p);
}

int main() {
    long long N=0,X=0;
    cin >> N >> X;

    vector<long long> w(N+1),p(N+1);
    w.at(0) = 1;
    p.at(0) = 1;
    for(int i=1; i<=N; i++){
        w.at(i) = w.at(i-1)*2+3;
        p.at(i) = p.at(i-1)*2+1;
    }
    long long ans = calP(N,X,w,p);
    cout << ans << endl;
    return 0;
}
