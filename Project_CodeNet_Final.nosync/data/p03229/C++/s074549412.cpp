#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e16+7;
int mod = 1e9+7;
int dx[4] = {1,-1, 0, 0};
int dy[4] = {0, 0, 1,-1};
signed main() {
    int N;
    cin >> N;
    vector<int>A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(),A.end());
    vector<int>cnt(4);
    for(int i = 0; i < N; i++) {
        if(i == 0) {
            cnt[2]++;
        }
        else if(i+1 == N) {
            if(i%2 == 0) {
                cnt[2]++;
            }
            else {
                cnt[1]++;
            }
        }
        else {
            if(i%2 == 0) {
                cnt[3]++;
            }
            else {
                cnt[0]++;
            }
        }
    }
    int ans = 0,now = 0;
    for(int i = 0; i < cnt[0]; i++) {
        ans-=A[now]*2;
        now++;
    }
    for(int i = 0; i < cnt[1]; i++) {
        ans-=A[now];
        now++;
    }
    for(int i = 0; i < cnt[2]; i++) {
        ans+=A[now];
        now++;
    }
    for(int i = 0; i < cnt[3]; i++) {
        ans+=A[now]*2;
        now++;
    }
    vector<int>cnt2(4);
    for(int i = 0; i < N; i++) {
        if(i == 0) {
            cnt2[1]++;
        }
        else if(i+1 == N) {
            if(i%2 == 0) {
                cnt2[1]++;
            }
            else {
                cnt2[2]++;
            }
        }
        else {
            if(i%2 == 0) {
                cnt2[0]++;
            }
            else {
                cnt2[3]++;
            }
        }
    }
    now = 0;int res = 0;
    for(int i = 0; i < cnt2[0]; i++) {
        res-=A[now]*2;
        now++;
    }
    for(int i = 0; i < cnt2[1]; i++) {
        res-=A[now];
        now++;
    }
    for(int i = 0; i < cnt2[2]; i++) {
        res+=A[now];
        now++;
    }
    for(int i = 0; i < cnt2[3]; i++) {
        res+=A[now]*2;
        now++;
    }
    cout << max(ans,res) << endl;
}
