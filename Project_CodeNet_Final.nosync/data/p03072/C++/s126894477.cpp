#include <bits/stdc++.h>
using namespace std;
#define rep0(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main(){
    int n;cin>>n;
    vector<int> h(n);
    rep0(i,n){
        cin>>h[i];
    }
    int ans=1;
    
    rep1(i,n){
        bool b=true;
        rep0(j,i){
            if(h[j]>h[i]){
                b=false;
            }
        }
        if(b){
            ans++;
        }
    }
    cout <<ans<<endl;
}