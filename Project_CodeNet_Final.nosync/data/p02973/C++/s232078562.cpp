#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1000000007;
ll INF=2000000000;

int main(){
    ll N;
    cin>>N;
    vector<ll> A(N);
    for(ll i=0; i<N; i++){
        cin>>A[i];
    }
    reverse(A.begin(), A.end());
    vector<ll> B(0);
    B.push_back(A[0]);
    ll BSz=1;
    for(int i=1; i<N; i++){
        auto It=upper_bound(B.begin(), B.end(), A[i]);
        if(It-B.begin()==BSz){
            B.push_back(A[i]);
            BSz ++;
        }
        else{
            B.at(It-B.begin())=A[i];
        }
      	/*for(int j=0; j<BSz; j++){
          	cout<<B[j]<<" ";
        }
      	cout<<endl;*/
    }
    cout<<BSz<<endl;
    return 0;
}