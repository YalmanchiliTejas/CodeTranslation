#include <iostream>
#define MAX 110

using namespace std;

int n,m;
char cr;
bool a[MAX][MAX],l[MAX],c[MAX];

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++){
        cin>>cr;
        if(cr!='.')a[i][j]=1;
        if(a[i][j])
          l[i]=c[j]=1;
      }
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++)
        if(l[i]&&c[j])
          cout<<((a[i][j])?'#':'.');
      if(l[i])
        cout<<'\n';
    }
    return 0;
}
