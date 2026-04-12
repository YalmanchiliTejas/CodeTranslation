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

void solve(long long N, std::string resp){
    bool sws[N]; // true->S
    vector<vector<bool>> inis={{true, true}, {false, false}, {true, false}, {false, true}};
    auto f = [](char r, bool curr, bool prev){
        if(curr && r=='o')return prev;
        if(curr && r=='x')return !prev;
        if(!curr && r=='o')return !prev;
        if(!curr && r=='x')return prev;
        throw "input invalid";
    };
    for(auto ini: inis){
        sws[0]=ini[0];
        sws[1]=ini[1];
        for(LL i=1; i<N-1; i++)sws[i+1]=f(resp[i], sws[i], sws[i-1]);

        if(f(resp[0], sws[0], sws[1]) == sws[N-1] && f(resp[N-1], sws[N-1], sws[N-2]) == sws[0]){
            for(LL i=0; i<N; i++)cout << (sws[i] ? 'S' : 'W');
            cout << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::string s;
    std::cin >> s;
    solve(N, s);
    return 0;
}
