#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;


int main(){
    ll N, X, M;
    cin >> N >> X >> M;

    vector<ll> A;
    A.push_back(X);
    A.push_back(X);

    int flag[M];
    for (int i = 0; i < M; ++i){
        flag[i] = 0;
    }
    flag[X] = 1;

    int index = 2;
    ll next;
    for (; index < M + 2; ++index){
        next = A[index - 1] * A[index - 1] % M;
        A.push_back(next);
        if (flag[next] != 0) break;
        flag[next] = index;
    }

    ll sum[index + 1];
    sum[0] = 0;
    for (int i = 1; i < index + 1; ++i){
        sum[i] = sum[i - 1] + A[i];
    }
    int start = flag[A[index]];


    ll ans;
    ans = sum[start];

    N -= start;

    int l = index - flag[next];
    ans += (N / l) * (sum[index] - sum[start]);

    ans += sum[flag[next] + (N % l)] - sum[flag[next]];

    cout << ans << endl;

}