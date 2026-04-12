#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define sayyes cout<<"Yes"<<endl;
#define sayno cout<<"No"<<endl;
#define vv(a,b) vector< vector<int> > v(a,vector<int>(b,0));
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
typedef tuple<int,int,int>T;
const int mod =1e9+7;
vector< vector<int> >ab;

int ans;
void bfs(int x,vector<bool> a)
{
    if(find(a.begin(),a.end(),false)==a.end())
    {
        ans++;
        return ;
    }
    rep(i,ab[x].size())
    {
        if(!a[ab[x][i]])
        {
            a[ab[x][i]]=true;
            bfs(ab[x][i],a);
            a[ab[x][i]]=false;

        }
    }
    
    

}


int main()
{
    int n,m;
    cin>>n>>m;
    ans=0;
    ab=vector< vector<int> >(n);
    rep(i,m)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;
        ab[a].push_back(b);
        ab[b].push_back(a);
    }
    vector<bool> temp(n,false);
    temp[0]=true;
    bfs(0,temp);
    cout<<ans;
    
}
