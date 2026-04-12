#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <climits>
using namespace std;

int count(vector<long long> &v){
    int cnt = 0;
    int N = v.size();
    while(true){
        long long mx = -1;
        for(int i=0; i<N; i++)
            mx = max(mx, v[i]);
        if(mx <= N-1) break;

        mx = -1;
        int j;
        for(int i=0; i<N; i++){
            if(v[i] > mx){
                mx = v[i];
                j = i;
            }
        }
        v[j] -= N+1;
        for(int i=0; i<N; i++) v[i]++;

        cnt++;
    }
    return cnt;
}

long long solve(vector<long long> a){
    int N = a.size();
    long long K = 0;
    while(true){
        sort(a.begin(), a.end(), greater<long long>());
        long long cnt = a[0] / N;
        if(cnt == 0) break;
        K += cnt;
        a[0] -= N * cnt;
        for(int i=1; i<N; i++) a[i] += cnt;
    }
    return K;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<long long> a(N);
    for(int i=0; i<N; i++) cin >> a[i];

    cout << solve(a) << endl;

    return 0;
}