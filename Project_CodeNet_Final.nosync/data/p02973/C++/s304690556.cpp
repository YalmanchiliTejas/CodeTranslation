#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <numeric>
#include <utility>
#define sign(a) ((a>0)-(a<0))
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define LL long long
#define INF (LL)(1LL<<60)

using namespace std;

void solve(long long N, std::vector<long long> A){
    vector<LL> seq = {-A[0]};
    for(LL i=1; i<N; i++){
        LL tmp = -A[i];
        if(tmp >= *seq.rbegin()){
            seq.emplace_back(tmp);
        }else{
            auto it = upper_bound(seq.begin(), seq.end(), tmp);
            *it = tmp;
        }
    }
    cout << seq.size() << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, std::move(A));
    return 0;
}
