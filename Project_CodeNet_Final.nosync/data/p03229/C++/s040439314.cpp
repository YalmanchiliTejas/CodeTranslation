#include "bits/stdc++.h"
using namespace std;
int main(){
    int N,i;
    long long int ans,tmp;
    cin >> N;
    vector<int> A(N);
    for(i=0;i<N;i++) cin >> A.at(i);
    sort(A.begin(),A.end());
    if(N%2){
        ans = 0;
        for(i=0;i<N/2;i++) ans -= A.at(i);
        for(i=N/2;i<N;i++) ans += A.at(i);
        ans *= 2;
        ans -= A.at(N/2) + A.at(N/2+1);
        tmp = 0;
        for(i=0;i<N/2+1;i++) tmp -= A.at(i);
        for(i=N/2+1;i<N;i++) tmp += A.at(i);
        tmp *= 2;
        tmp += A.at(N/2)+A.at(N/2-1);
        ans = max(ans,tmp);
    }else{
        ans = 0;
        for(i=0;i<N/2;i++) ans -= A.at(i);
        for(i=N/2;i<N;i++) ans += A.at(i);
        ans *= 2;
        ans += A.at(N/2-1) - A.at(N/2);
        tmp = 0;
        for(i=0;i<N/2;i++) tmp -= A.at(i);
        for(i=N/2;i<N;i++) tmp += A.at(i);
        tmp *= 2;
        tmp += A.at(N/2-1)-A.at(N/2);
        ans = max(ans,tmp);   
    }
    cout << ans << endl;
    return 0;
}