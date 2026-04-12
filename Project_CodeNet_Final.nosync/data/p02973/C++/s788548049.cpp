#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
const int MOD = ((int)1e9)+7;
const int INF = (int)(1e9)+(int)(1e7);
const ll INFL = (ll)(1e18)+INF;
const double EPS = 1e-8;
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<int>dp;
    rep(i,N){
        int a;
        cin >> a;
        a=(int)1e9-a;
        if(dp.size()==0){
            dp.push_back(a);
            continue;
        }
        int l=-1;
        int r=dp.size();
        while(r-l>1){
            int mid=(l+r)/2;
            if(dp[mid]<=a){
                l=mid;
            }
            else{
                r=mid;
            }
        }
        if(r==dp.size()){
            dp.push_back(a);
        }
        else{
            dp[r]=min(dp[r],a);
        }
    }
    cout << dp.size() << endl;
    
    return 0;
}