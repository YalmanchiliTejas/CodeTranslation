#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) v.begin(),v.end()

using namespace std;
typedef long long ll;




int main()
{
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];
    sort(all(A));
    vector<ll> B;
    vector<ll> C;
    int n = 0;
    
    for (int i = 0; i < N/2+1; i++) {
        if(n==N-1 && abs(B.front()-A[N-1-i]) > abs(B.back()-A[N-1-i])){
            B.insert(B.begin(), A[N-1-i]);
            break;
        }else if(n==N-1){
            B.push_back(A[N-1-i]);
            break;
        }
        n++;
        B.push_back(A[N-1-i]);
        if(n==N-1 && abs(B.front()-A[i]) > abs(B.back()-A[i])){
            B.insert(B.begin(), A[i]);
            break;
        }else if(n==N-1){
            B.push_back(A[i]);
            break;
        }
        n++;
        B.push_back(A[i]);
    }
    
    n = 0;
    for (int i = 0; i < N/2+1; i++) {
           
        if(n==N-1 && abs(C.front()-A[i]) > abs(C.back()-A[i])){
            C.insert(C.begin(), A[i]);
            break;
        }else if(n==N-1){
            C.push_back(A[i]);
            break;
        }
        n++;
        C.push_back(A[i]);
        if(n==N-1 && abs(C.front()-A[N-1-i]) > abs(C.back()-A[N-1-i])){
            C.insert(C.begin(), A[N-1-i]);
            break;
        }else if(n==N-1){
            C.push_back(A[N-1-i]);
            break;
        }
        n++;
        C.push_back(A[N-1-i]);
        
    }
 
    
    ll ans = 0;
    ll an = 0;
    for (int i = 1; i < N; i++) {
        ans += abs(B[i]-B[i-1]);
        an += abs(C[i]-C[i-1]);
    }
    cout << max(ans, an) << endl;
    
    return 0;
}

