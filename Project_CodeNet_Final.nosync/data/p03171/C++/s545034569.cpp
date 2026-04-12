#include <bits/stdc++.h>
#include <math.h>


    using namespace std;
    typedef long long ll;
    # define M_PI  3.14159265358979323846
    const int MOD=1e9+7;

    long long dp[3005][3005][2];

    long long solve(vector<int>& a, int i, int j,int turn){
        if(i>j)
            return 0;
        if(dp[i][j][turn]!=-1)
            return dp[i][j][turn];
        if(turn ==1)
            return dp[i][j][turn]=max(a[i]+solve(a,i+1,j,0),a[j]+solve(a,i,j-1,0));
        else
            return dp[i][j][turn]=min(solve(a,i+1,j,1),solve(a,i,j-1,1));
    }

    void solve(){
        int n;
        cin>>n;
        vector<int>a(n);
        long long s=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            s+=(long long)a[i];
        }
        memset(dp,-1,sizeof(dp));
        long long sx=solve(a,0,n-1,1);
//        cout<<sx<<"\n";
//        cout<<s<<"\n";
        long long sy=s-sx;
        cout<<sx-sy;
        return;
    }

    int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cout<<fixed;
        cout<<setprecision(10);
        int t=1;
//        cin>>t;
        for(int i=1;i<=t;i++){
            solve();
        }
        return 0;
    }
