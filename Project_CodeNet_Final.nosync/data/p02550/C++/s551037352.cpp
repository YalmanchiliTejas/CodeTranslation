#include <bits/stdc++.h>
using namespace std;


const long long MOD = 998244353;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    map<long long unsigned int,pair<long long unsigned int,long long unsigned int > > cycleDetection;

    long long unsigned N,X,M;
    cin>>N>>X>>M;

    long long unsigned res = 0;
    bool already = false;
    for(long long unsigned c = 0; c < N; c++) {
        if(!already && cycleDetection.find(X) != cycleDetection.end()) {
            already = true;
            long long unsigned c2 = cycleDetection[X].first;
            long long unsigned previousRes = cycleDetection[X].second;
            long long unsigned delta = res - previousRes;
            long long unsigned length = (c - c2);
            long long unsigned z = (N-c) / length;
            res += delta * z;
            c += z*length;
            c--;
        } else {
            cycleDetection[X] = make_pair(c,res);
            res += X;
            X = (X*X)%M;
        }
    }
    cout<<res;
}
