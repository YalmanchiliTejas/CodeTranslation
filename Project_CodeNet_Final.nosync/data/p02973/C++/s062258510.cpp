#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    ll n;
    cin >> n;
    vector <ll> a(n);
    rep(i,n){
        cin >> a[i];
    }

    vector <ll> ans;
    
    ans.push_back(1001001001001001);
    ans.push_back(a[0]);
    
    ll r,l,m;

    rep(i,n){
        if(i!=0){
            r=ans.size();
            if(a[i]<=ans[r-1]){
                ans.push_back(a[i]);
                //sort(ans.begin(),ans.end());
            }
            else{
                r=ans.size()-1;
                l=0;
                while((r-l)>1){
                    m=(r+l)/2;
                    if(ans[m]<a[i]){
                        r=m;
                    }
                    else{
                        l=m;
                    }
                }
                ans[r]=a[i];   
            }
        }
    }

    cout << ans.size()-1 << endl;
    

    return 0;
}