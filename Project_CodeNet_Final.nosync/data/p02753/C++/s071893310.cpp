#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ull = unsigned long long int;

#define MATHPI acos(-1)

template<class T> void chmax(T &a, T b) {
    if (a < b) a = b;
}
template<class T> void chmin(T &a, T b) {
    if (b < a) a = b;
}

using Mat = vector<vector<ll>>;
using Column = vector<ll>;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string S;
    cin>>S;
    if (S=="AAA" || S=="BBB") {
        cout <<"No"<<"\n";
    } else {
        cout <<"Yes"<<"\n";
    }

    return 0;
}