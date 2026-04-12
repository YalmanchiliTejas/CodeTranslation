#include <iostream>
using namespace std;
int n,m;
char c[101][101];
bool ok,b[101];
int main()
{ cin>>n>>m;
  for(int i=1;i<=n;i++)
  { ok=0;
    for(int j=1;j<=m;j++)
    { cin>>c[i][j];
      if(c[i][j]=='#')
         ok=1,b[j]=1;
    }
    if(!ok)
       i--,n--;
  }
  for(int i=1;i<=n;i++)
  { for(int j=1;j<=m;j++)
    { if(b[j])
         cout<<c[i][j];
    }
    cout<<'\n';
  }
  return 0;
}
