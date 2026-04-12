#include<bits/stdc++.h>

using namespace std;


int main()
{
          int n,m;
          int ans=0;
          cin>>n>>m;
          for(int i=0;i<n;i++)
                    for(int j=0;j<m;j++)
                    {
                              char c;
                              cin>>c;
                              ans+=(c=='#');
                    }
          if(ans==n+m-1)
                    cout<<"Possible";
          else
                    cout<<"Impossible";
}
