#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    sort(A.begin(),A.end());
    ll big=0;
    ll small =0;
    if(N%2==0){
        for(int i=0;i<N;i++){
            if(i<(N/2)){
                small += 2*A[i];
            }else{
                big += 2*A[i];
            }
        }
        small -= A[(N/2)-1];
        big -= A[(N/2)];
        cout << big -small << endl;
        return 0;
    }
    ll ans = 0;
    {
        for(int i=0;i<N;i++){
            if(i<(N/2)){
                small += 2*A[i];
            }else{
                big += 2*A[i];
            }
            
        }
        big -= (A[N/2] + A[(N/2) +1]);
        ans = big -small;
    }
    {
        big =small =0;
        for(int i=0;i<N;i++){
            if(i<(N/2)+1){
                small += 2*A[i];
            }else{
                big += 2*A[i];
            }
           
        }
         small -= (A[N/2] + A[(N/2) -1]);
        ans = max(ans,big -small);
    }
    cout << ans << endl;
    return 0;
}