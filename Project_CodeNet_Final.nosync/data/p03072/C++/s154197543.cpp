#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;

int main(){
    int N; cin >> N;
    vector <int> A(N);
    rep(i,N) cin >> A[i];
    
    int ans=0;
    int cnt=0;
    for (int i=N-1; i>0; i--){
        for(int j=i-1; j>=0; j--){
            if(A[i]<A[j]){
                cnt++;
                break;
            }
        }
    }
    ans=(N-1)-cnt+1;
    cout << ans;
}