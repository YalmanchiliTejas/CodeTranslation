#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
#define pb push_back
#define powerof2 ()
using ll = long long;
const ll M = 1000000007;
const ll infi = 1000000000000000;
const ll md = 998244353;
using vl = vector<ll>;
using pll =  pair<ll,ll>;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> is;
ll power(ll x,ll y){
    if(y==0)
    return 1;
    ll res=power(x,y/2);
    res=(res*res)%M;
    if(y&(ll)1)
    res=(res*x)%M;
    return res;
}


/*int n,ma=0;
vector<vector<int>> gr;
vector<int> color;
void dfs(int c,int p)
{
    vector<int> v;
    int j;
    for(j=1;j<gr[c].size()+2;j++)
    {
        if(j==color[c]||j==color[p])
        continue;
        //cout<<j<<" ";
        v.pb(j);
    }
    //cout<<endl;
    j=0;
    for(int i=0;i<gr[c].size();i++)
    {
        if(gr[c][i]!=p)
        {
            color[gr[c][i]]=v[j];j++;
            dfs(gr[c][i],c);
        }
    }
}*/
void solve(){
    string s;
    cin>>s;
    if(s[0]!=s[2]||s[0]!=s[1])
    cout<<"Yes"<<endl;
    else
    cout<<"No"<<endl;
}
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // int t;
    // cin>>t;
    // while(t--)
    solve();
    return 0;
}