#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define pii make_pair
int ceil(int a, int b) { if(a%b==0) return a/b; else return a/b+1; }
bool checkbit(int pos, int mask) { return mask&(1<<pos); }
int turnon(int pos, int mask) { return mask|(1<<pos); }

vector<int>num;
int dp[105][4][2];
int k;

int fun(int pos, int cnt, int fl)
{
    if(pos==num.size()) {
        if(cnt==k) return 1;
        else return 0;
    }
    if(dp[pos][cnt][fl]!=-1) {
        //cout<<"SDF";
        return dp[pos][cnt][fl];
    }
    int ans=0, lim;
    if(!fl) lim=num[pos];
    else lim=9;
    for(int i=0; i<=lim; i++) {
        int nf=fl, nc=cnt;
        if(!fl && i<lim) nf=1;
        if(i!=0) nc++;
        if(nc<=k) ans+=fun(pos+1, nc, nf);
    }
    return dp[pos][cnt][fl]=ans;
}

int solve(string a)
{
    memset(dp, -1, sizeof(dp));
    for(int i=0; i<a.size(); i++) {
        num.push_back(a[i]-'0');
    }
    int ans=fun(0, 0, 0);
    return ans;
}

main()
{
    string n;
    cin>>n>>k;
    cout<<solve(n);
}
