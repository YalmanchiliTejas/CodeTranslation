#include <bits/stdc++.h>
using namespace std;

int main() {
   int n,m;
    cin>>n>>m;vector<string > v(n);
    for(int i=0;i<n;i++)
    {
      cin>>v[i];
    }bool r[n]={0};bool c[m]={0};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(v[i][j]=='#')
            {
                r[i]=1;
                c[j]=1;
            }
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        //cout<<r[i]<<" ";
        if(r[i]==0)
        {v.erase(v.begin()+i-cnt);cnt++;}
    }
     for(int i=0;i<v.size();i++)
    {
      //  cout<<v[i]<<endl;
    }
    for(int i=0;i<v.size();i++)
    {cnt=0;
        for(int j=0;j<m;j++)
        {
            if(c[j]==0)
            {
               // cout<<j<<" "<<v[i]<<" ";
                v[i]=v[i].substr(0,j-cnt).append(v[i].substr(j-cnt+1,v[i].size()-j+cnt-1));cnt++;
                //cout<<v[i];
            }
        }
        cout<<v[i]<<endl;
    }
    
    
    
    return 0;
}