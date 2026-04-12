// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll dp[(1<<8)+10][10];
int Set(int n , int pos)
{
    return n|(1<<pos);
}
bool Check(int n , int pos)
{
    return n&(1<<pos);
}
vector<int>edges[10];
int n , m;

ll f(int mask , int u)
{
    if(mask==(1<<n)-1)return 1;
    if(dp[mask][u]!=-1)return dp[mask][u];
    ll value = 0;
    for(auto v:edges[u]){
        if(Check(mask , v)==false){
            value+=f(Set(mask , v) , v);
        }
    }
    return dp[mask][u] = value;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for(int i=0;i<m;i++){
        int in1 , in2;
        cin >> in1 >> in2;
        in1--;
        in2--;
        edges[in1].push_back(in2);
        edges[in2].push_back(in1);
    }
    memset(dp , -1 , sizeof(dp));
    ll ans = 0;
    int mask = Set(0 , 0);
    for(int i=0;i<edges[0].size();i++){
        ans+=f(Set(mask , edges[0][i]) , edges[0][i]);
    }
    cout << ans << endl;
    return 0;
}
