#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int INF = 1e9;
int MOD = 1e9+7;
main(){
    int N;
    ll A[50],cnt = 0;
    cin >> N;
    for(int i = 0;i < N;i++)cin >> A[i];
    while(1){
        ll dif = 0,maxi = 0;
        for(int i = 0;i < N;i++){
            ll num = A[i]/N;
            A[i] -= num*(N+1);
            dif += num;
        }
        for(int i = 0;i < N;i++){
            A[i] += dif;
            maxi = max(maxi,A[i]);
        }
        cnt += dif;
        if(maxi < N)break;
    }
    cout << cnt << endl;
}