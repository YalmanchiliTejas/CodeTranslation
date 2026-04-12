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
// using Graph = vector<vector<bool>>;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,M;cin>>N>>M;
    vector<vector<bool>> g(N+1, vector<bool>(N+1, false));
    
    for (size_t i = 0; i < M; i++)
    {
        int a,b;cin>>a>>b;
        g[a][b] = true;
        g[b][a] = true;
    }

    vector<int> B;
    for (int i = 0; i < N; i++) {
        B.push_back(i+1);
    }

    int cnt=0;
    do {
        bool connected =true;
        for (size_t i = 0; i < N-1; i++)
        {
            if(!g[B[i]][B[i+1]]) {
                connected = false;
                break;
            }
        }
        if(connected) {
            cnt++;
        }
    } while(next_permutation(B.begin() + 1, B.end()));

    cout << cnt<<"\n";
    

    return 0;

}