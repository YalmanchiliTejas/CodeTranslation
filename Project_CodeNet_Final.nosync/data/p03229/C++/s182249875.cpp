#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i, n) for(int i =0; i < n ;i++)
using namespace std;
long long A[100005];
long long b[100005];

int main(){
    int N;
    long long ans =0;
    cin >> N;

    for(int i =0; i < N ; i++){
        cin >>A[i];
    }

    //sort(A, A+N, std::greater<int>());
    sort(A, A+N);

    if(N % 2==0){
        int c = N/2;
        rep(i, c){
            if(i % 2==0){
                b[c+i] = A[i];
                b[c-i-1] = A[N-1-i];
            }
            else{
                b[c+i] = A[N-1-i];
                b[c-i-1] = A[i];
            }
        }
        rep(i, N-1){
            ans += abs(b[i+1]- b[i]);
        }
        
    }
    else{
        int c = (N+1)/2 - 1;
        b[c] = A[0]; 
        rep(i, c){
            if(i % 2==0){
                b[c+1+i] = A[N-1-i];
                b[c-1-i] = A[N-2-i];
            }
            else{
                b[c+i+1] = A[i];
                b[c-i-1] = A[i+1];
            }
        }
        long long tempans=0;
        rep(i, N-1){
            tempans += abs(b[i+1]- b[i]);
        }

        b[c] = A[N-1]; 
        rep(i, c){
            if(i % 2==0){
                b[c+i+1] = A[i];
                b[c-i-1] = A[i+1];
            }
            else{
                b[c+i+1] = A[N-1-i];
                b[c-i-1] = A[N-2-i];
            }
        }
        ans = tempans;
        tempans=0;
        rep(i, N-1){
            tempans += abs(b[i+1]- b[i]);
        }
        ans = max(ans, tempans);
    }
    cout << ans << endl;
    return 0;

   
}