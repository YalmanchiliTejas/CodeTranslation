#include <bits/stdc++.h>

int main() {
    using namespace std;
    string N;
    cin >> N;
    unsigned long K;
    cin >> K;
    cout << [rec_impl = [](auto f, auto beg, auto edn, unsigned long K) -> unsigned long {
        if(K == 0)return 1;
        string N(beg, edn);
        if(N.size() < K)return 0;
        unsigned long c{1};
        for(unsigned long i{1}; i < K; ++i)(c *= 9 * (N.size() - i)) /= i;
        return ((N[0] - 49) * K + 9 * (N.size() - K)) * c / K + f(f, find_if_not(N.begin() + 1, N.end(), [](auto t){return t == '0';}), N.end(), K - 1);
    }](string N, unsigned long K){return rec_impl(rec_impl, N.begin(), N.end(), K);}(N, K) << endl;
    return 0;
}