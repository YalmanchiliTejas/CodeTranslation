#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    long long int ans=0,tmp=0;
    vector<long long int> A(N);
    for(int i=0;i<N;i++){
        cin >> A[i];
    }

    sort(A.begin(),A.end());

    if(N%2==0){
        for(int i=0;i<N/2;i++){
            if(i==N/2 -1){
                ans -= A[i];
            }else{
                ans -= 2*A[i];
            }
        }

        for(int i=N/2;i<N;i++){
            if(i==N/2){
                ans += A[i];
            }else{
                ans += 2*A[i];
            }
        }
    }else{
        for(int i=0;i<=N/2;i++){
            if(i==N/2 -1 || i==N/2){
                ans -= A[i];
            }else{
                ans -= 2*A[i];
            }
        }

        for(int i=N/2 + 1;i<N;i++){
            ans += 2*A[i];
        }

        for(int i=0;i<N/2;i++){
            tmp -= 2*A[i];
        }

        for(int i=N/2;i<N;i++){
            if(i==N/2 || i==N/2+1){
                tmp += A[i];
            }else{
                tmp += 2*A[i];
            }
        }
    }

    cout << max(tmp,ans) << endl;
}