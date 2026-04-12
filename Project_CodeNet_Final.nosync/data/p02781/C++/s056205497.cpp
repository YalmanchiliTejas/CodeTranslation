
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[102][2][5];
int k, sz;
vector<int> v;
ll fun(int pos, int small, int cnt)
{
    if(pos==sz) return cnt==k;
    if(cnt>k) return 0;
    ll& ret = dp[pos][small][cnt];
    if(ret!=-1) return ret;
    ret = 0;
    int lim;
    if(small) lim = 9;
    else lim = v[pos];
    for(int i=0; i<=lim; i++){
        ret+=fun(pos+1, small||(i<lim), cnt+(i>0));
    }
    return ret;
}
int main()
{
    memset(dp, -1, sizeof dp);
    string str;
    cin>>str;
    cin>>k;
    sz = str.size();
    v.resize(sz);
    for(int i=sz-1; i>=0; i--)
        v[i] = str[i]-'0';
    cout<<fun(0,0,0)<<endl;
}
