#include <bits/stdc++.h>
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) rep(i,0,n)
using namespace std;


int m,n,ans=0;
vector<vector<int>>tree(10);
vector<bool>flag(10,false);
void DFS(int x)
{
   
    flag.at(x)=1;
   // for(int x:flag){cout<<x;}cout<<endl;
    bool tf=1;
    REP(i,n)
    {
        tf&=flag.at(i);
    }
    if(tf==1)ans++;
    
        REP(i,tree.at(x).size())
        {
            if(flag.at(tree.at(x).at(i))==0)
            {
                DFS(tree.at(x).at(i));
                flag.at(tree.at(x).at(i))=0;
            }
        }
}

int main()
{
    cin>>n>>m;
    
    REP(i,m)
    {
        int a,b;
        cin>>a>>b;
        tree.at(a-1).push_back(b-1);
        tree.at(b-1).push_back(a-1);
    }
    DFS(0);
    cout<<ans<<endl;

}