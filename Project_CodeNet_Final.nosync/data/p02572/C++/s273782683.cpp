#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;

class solution{
public:
    long long pairProduct(vector<int>& A, int n){
        unsigned long long sum=0;
        for(int i=0; i<n; ++i) sum+=A[i];
        long long ans=0;
        for(int i=0; i<n; ++i){
            sum-=A[i];
            ans = (ans + ((sum%MOD)*(A[i]%MOD))%MOD)%MOD;
        }
        return ans;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i=0; i<n; ++i) cin>>A[i];
    solution solve = solution();
    long long ans = solve.pairProduct(A, n);
    cout<<ans<<"\n";
}