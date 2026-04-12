#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(int)(n);i++)
using ll = unsigned long long;
using P = pair<int, int>;

int main(){
    int n;
    cin >> n;
    vector<ll> a(n,0);
    rep(i, n){
        cin >> a.at(i);
    }
    ll sum=0;
    vector<ll> b(n-1,0);
    rep(i, n-1){
        if(i==0){
          b.at(n-2-i)=a.at(n-1-i);
        } else {
          b.at(n-2-i)=b.at(n-1-i)+a.at(n-1-i);
        }
         b.at(n-2-i)%=1000000007;
    }

    rep(i, n-1){
        sum+=a.at(i)*b.at(i);
        sum%=1000000007;
    }
    cout << sum << endl;
}
