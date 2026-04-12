#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

int bs_upper_bound(int a[], int n, int x) {
    int l = 0;
    int h = n; // Not n - 1
    while (l < h) {
        int mid =  l + (h - l) / 2;
        if (x >= a[mid]) {
            l = mid + 1;
        } else {
            h = mid;
        }
    }
    return l;
}

int bs_lower_bound(int a[], int n, int x) {
    int l = 0;
    int h = n; // Not n - 1
    while (l < h) {
        int mid =  l + (h - l) / 2;
        if (x <= a[mid]) {
            h = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

bool sortbysec(const pair<int,int> &a,const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
} 

int n;
vector<ll> a;

/*ll solve(int l,int r,int play){
    if(l==r){
        if(play==1)
            return -1*a[l];
        else
            return a[l];
    }
    else{
        if(play==0)
            return max(a[l]+solve(l+1,r,!play),a[r]+solve(l,r-1,!play));
        else
            return min(-1*a[l]+solve(l+1,r,!play),-1*a[r]+solve(l,r-1,!play));
    }
}*/

int main()
{
    IOS;
    cin>>n;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        a.push_back(x);
    }
    ll dp[n][n][2];
    for(int i=n-1;i>=0;i--){
        dp[i][i][1]=-1*a[i];
        dp[i][i][0]=a[i];
        for(int j=i+1;j<n;j++){
            dp[i][j][0]=max(a[i]+dp[i+1][j][1],a[j]+dp[i][j-1][1]);
            dp[i][j][1]=min(-1*a[i]+dp[i+1][j][0],-1*a[j]+dp[i][j-1][0]);
        }
    }
    cout<<dp[0][n-1][0];
}
