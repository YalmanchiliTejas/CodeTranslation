#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,sumW;
    cin>>n>>m;
    string arr[n];
    bool row[n]={0},col[m]={0};
    for(int i=0; i<n; i++)

        cin>>arr[i];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(arr[i][j]=='#'){
                row[i]=1;col[j]=1;
            }

  for(int i=0;i<n;i++)
  {
      if(row[i])
      {
          for(int j=0;j<m;j++)
          {
              if(col[j])
                cout<<arr[i][j];
          }
          cout<<endl;
      }

  }



    return 0;
}
