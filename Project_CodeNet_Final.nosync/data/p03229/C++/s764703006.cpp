#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(long long (i)=0, i_N=(n); (i)<i_N; (i)++)
using namespace std;
using ll = long long;
template<typename T> ostream& operator<< (ostream& s, vector<T> P){
    for(int i=0; i<P.size(); i++){if(i){s<<" ";} cout<<P[i];} return s;
}
int main(){
    ll N; cin>>N;
    vector<ll> A(N);
    rep(i, N) cin>>A[i];
    sort(A.begin(), A.end());
    ll l = A[0]; 
    ll r = A[0]; 
    ll cnt = 1;
    ll i=1, j=N-1;
    ll res = 0;
    while(i<N and j>=0 and cnt<N){
        ll lcost = max(abs(A[i]-l), abs(A[i]-r));
        ll rcost = max(abs(A[j]-l), abs(A[j]-r));
        if(lcost>rcost){
            res += lcost;
            if(abs(A[i]-l) > abs(A[i]-r)) l = A[i];
            else r = A[i];
            i++;
            cnt++;
        }
        else{
            res += rcost;
            if(abs(A[j]-l) > abs(A[j]-r)) l = A[j];
            else r = A[j];
            j--;
            cnt++;
        }
    }
    cout << res << endl;
    return 0;
}