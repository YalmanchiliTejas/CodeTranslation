#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,a,b) for(int i=a;i<b+1;i++)
#define Per(i,b,a) for(int i=b;i>=a;i--)

int main(){
    int N;
    cin>>N;
    ll A[100000];
    rep(i,N) cin>>A[i];
    vector<ll> vec;
    vec.push_back(A[0]);
    Rep(i,1,N-1){
        auto itr = lower_bound(vec.begin(), vec.end(),A[i]);
        if(itr == vec.begin()) vec.insert(vec.begin(),A[i]);
        else{
            --itr;
            *itr = A[i];
        }
    }
    cout<<vec.size()<<endl;

    return 0;
}