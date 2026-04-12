#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(s,i, n) for (int i = (int)s; i < (int)(n); i++)
#define pb push_back
typedef long long ll;
  
int main(){
    int n;
    cin>>n;
    int high=0;
    int ans=0;
    rep(i,n){
        int h;
        cin>>h;
        if(high<=h)ans++;
        if(h>=high)high=h;
    }
    cout<<ans<<endl;

    
    return 0;
}