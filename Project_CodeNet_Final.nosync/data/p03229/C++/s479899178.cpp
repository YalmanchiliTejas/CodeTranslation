#include <algorithm>
#include <string>
#include <iostream>
#include <cstdlib>

#define REP(i,n) for(long long i = 0;i < n;i++)
typedef long long ll;

using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N = 0;
    cin >> N;
    ll A[N];
    REP(i,N){
        cin >> A[i];
    }
    ll co_large[N];
    //start by large
    if(N % 2 == 0) {
        ll num2 = (N - 2) / 2;
        REP(i,num2)
            co_large[i] = -2;
        co_large[num2] = -1;
        co_large[num2 + 1] = 1;
        for(int i = num2 + 2;i < N;i++)
            co_large[i] = 2;
    }else {
        ll num2 = (N - 2) / 2 + 1;
        REP(i,num2)
            co_large[i] = -2;
        co_large[num2] = 1;
        co_large[num2 + 1] = 1;
        for(int i = num2 + 2;i < N;i++)
            co_large[i] = 2;
    }
    //start by small
    ll co_small[N] = {};
    if(N %2 !=0){ //偶数個の時は大きいのから始めても小さいのから始めても同じ
        ll num2 = (N - 2) / 2;
        REP(i,num2)
            co_small[i] = -2;
        co_small[num2] = -1;
        co_small[num2 + 1] = -1;
        for(int i = num2 + 2;i < N;i++)
            co_small[i] = 2;
    }
    sort(A,A + N);
    ll diff_large = 0;
    REP(i,N){
        diff_large += A[i] * co_large[i];
    }
    ll diff_small = 0;
    REP(i,N){
        diff_small += A[i] * co_small[i];
    }
    ll diff = max(diff_small,diff_large);

    cout << diff << endl;



    return 0;
}
