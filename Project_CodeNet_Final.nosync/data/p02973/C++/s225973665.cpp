#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define print2(a, b) cerr << "(" << a << "," << b << ")" << endl
#define print3(a, b, c) cerr << "(" << a << "," << b << "," << c << ")" << endl


void solve(long long N, std::vector<long long> A){
    multiset<ll> s;
    s.insert(A[0]);
    for (int i = 1; i < N; i++) {
        auto it = s.lower_bound(A[i]);
        if (it == s.begin())
            s.insert(A[i]);
        else {
            it--;
            s.erase(it);
            s.insert(A[i]);
        }
    }
    cout << s.size() << endl;
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
