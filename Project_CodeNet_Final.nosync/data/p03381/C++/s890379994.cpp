#include<bits/stdc++.h>
using namespace std;

int main(){
    using namespace std;
    size_t N;
    cin >> N;
    vector<unsigned long> A(N), B(N);
    copy_n(istream_iterator<unsigned long>(cin), N, A.begin());
    copy_n(A.begin(), N, B.begin());
    nth_element(B.begin(), B.begin() + N / 2, B.end());
    auto s = *max_element(B.begin(), B.begin() + N / 2), t = B[N / 2];
    transform(A.begin(), A.end(), ostream_iterator<unsigned long>(cout, "\n"), [&s, t](auto a){return a < t ? t : s;});
}