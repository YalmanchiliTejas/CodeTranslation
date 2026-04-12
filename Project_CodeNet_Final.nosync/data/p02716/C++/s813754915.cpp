#include <bits/stdc++.h>

using namespace std;
long long mx=-1e17;
vector<long long>v;
vector<vector<long long> >dp(2e5+5,vector<long long>(3,-1ll));
vector<vector<long long> >dpvs(2e5+5,vector<long long>(3,0));
int n;
int cnt=0;
long long slv(int idx,int rmm,long long ttl=0ll){
    cnt++;
    int mv=idx-(((n%2)?2:1)-rmm);
    mv/=2;
    mv++;
    ///cout <<idx<< ' '<< rmm<< ' '<< ttl << endl;
    if(dpvs[idx][rmm]!=0)
        return dp[idx][rmm];
    long long ret=-1e17;
    if(mv==n/2){
        ret=max(ret,v[idx]);
        if(rmm)
            ret=max(ret,slv(idx+1,rmm-1));
        return ret;
    }
    if(idx>=n){
        return (long long)-1e17;
    }
    ret=max(ret,slv(idx+2,rmm)+v[idx]);
    if(rmm)
        ret=max(ret,slv(idx+1,rmm-1));
    dpvs[idx][rmm]=1;
    return dp[idx][rmm]=ret;
}
int main()
{
    cin>>n;
    v=vector<long long>(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout << slv(0,(n%2)?2:1) << endl;
    ///cout << cnt << endl;
    return 0;
}
