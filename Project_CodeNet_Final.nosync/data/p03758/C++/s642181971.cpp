#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(a)  (a).begin(),(a).end()
#define pb emplace_back
#define INF (1e9+1)
//#define INF (1LL<<59)

int main(){
    int n;
    cin>>n;
    
    vector<pii> ans;
    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>=i+1;j--){
            string s = string(n,'0');
            s[i] = s[j] = '1';
            cout<<"? "<<s<<endl;
            
            int res;
            cin>>res;
            if(res){
                ans.pb(pii(i,j));
            }
            if(ans.size()==n-1)goto end;
        }
    }
end:;
    cout<<"!";
    rep(i,ans.size()){
        cout<<" (";
        cout<<ans[i].first<<","<<ans[i].second;
        cout<<")";
    }
    cout<<endl;
}