#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#define DIVCEIL(A,B) ((A+(B-1))/B)
using namespace std;


void solve(long long N, long long M, std::vector<long long> a, std::vector<long long> b){
    vector<vector<int>> connected(N, vector<int>(N, 0));
    for(int i=0; i<M; i++){
        connected[a[i]-1][b[i]-1]++;
        connected[b[i]-1][a[i]-1]++;
    }
    vector<int> ordered(N, 0);
    long long ans=0ll;
    for(int i=0; i<N; i++)ordered[i]=i;
    do{
        int i;
        for(i=0; i<N-1; i++){
            if(!connected[ordered[i]][ordered[i+1]])break;
        }
        if(i==N-1)ans++;
    }while(next_permutation(ordered.begin()+1, ordered.end()));
    cout << ans << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    std::vector<long long> a(M);
    std::vector<long long> b(M);
    for(int i = 0 ; i < M ; i++){
        scanf("%lld",&a[i]);
        scanf("%lld",&b[i]);
    }
    solve(N, M, std::move(a), std::move(b));
    return 0;
}
