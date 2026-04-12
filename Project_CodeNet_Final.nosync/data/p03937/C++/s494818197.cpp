#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<functional>
#include<vector>
#include<map>
#include<cmath>
#include<string>
#include<bitset>
#include <sstream>
#include<queue>
#include<set>
#include<iomanip>
#define rep(i,n) for(ll i=0;i<(n);++i)
using namespace std;
typedef long long ll;
//typedef pair<int,int>P;
const int INF=10101;
const int H_MAX=8;
const int W_MAX=8;
vector< vector<char> > G(H_MAX,vector<char>(W_MAX));
vector< vector<bool> > P(H_MAX,vector<bool>(W_MAX,false));
bool flag=false;
int h,w;

void dfs(int i,int j )
{
    
    P[i][j]=true;
    if(G[i][j]=='.')return;
    if(i==h-1 && j==w-1)
    {
        flag=true;
        return;
    }
    if(G[i][j+1]!='.' && j+1<w)
    {
        dfs(i,j+1);
    }
    else if(G[i+1][j]!='.' && i+1<h)
    {
        dfs(i+1,j);
    }
    return;
}


int main()
{
    
    
    cin>>h>>w;
    rep(i,h)rep(j,w)
    {
        cin>>G[i][j];
    }
    dfs(0,0);
    bool printflag=true;
    rep(i,h)rep(j,w)
    {
        if(G[i][j]=='#' && !P[i][j])
        {
            printflag=false;
        }
    }
    if(flag && printflag)
    {
        cout<<"Possible";
    }
    else
    {
        cout<<"Impossible";
    }
}