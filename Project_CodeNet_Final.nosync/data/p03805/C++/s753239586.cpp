#include<bits/stdc++.h>
using namespace std;

int n,counter=0;

vector<int>adj[10];

bool Check(int n,int pos)
{
    return (n & (1<<pos));
}
int Set(int n,int pos)
{
    return (n | (1<<pos));
}

bool yo(int mask)
{
    int flag=0;
    for(int i=0;i<n;i++)
    {
        if(!Check(mask,i))flag++;
    }
    if(flag==0)return true;
    else return false;
}

void f(int mask,int pos)
{
  //  cout<<mask<<endl;
   if(yo(mask))
    {
        counter++;
        return ;
    }


    for(int i=0;i<adj[pos].size();i++)
    {
        if(!Check(mask,adj[pos][i]))
        {
            f(Set(mask,adj[pos][i]),adj[pos][i]);
        }
    }

}

int main()
{
    int m;
    cin>>n>>m;
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    f(1,0);
    cout<<counter<<endl;


}
