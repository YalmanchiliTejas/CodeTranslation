#include <iostream>
#include<cstring>
using namespace std;
int use[9];

int c[9][9];
int way(int start,int k,int n)
{

    if(k==1){return 1;}
    use[start]=1;

    int ans=0;
  /*      int t[9][9];
        memset(t,0,sizeof(t));
        if(connect[start][j]){
            memcpy(t,connect,(n+1)*(n+1));
            for(int k=1;k<n;k++){
                t[1][k]=t[n][k];
                t[k][1]=t[k][n];
            }
        }*/
    for(int j=1;j<=n;j++){
        if(use[j]==0&&c[start][j])
        {
            //cout<<start<<"->";
            ans+=way(j,k-1,n);

        }
       //else cout<<"end"<<endl;
       // else cout<<"c["<<start<<"]["<<j<<"]="<<c[start][j]<<endl;
    }
    use[start]=0;
    return ans;
}
int main()
{
   int m,n;
    memset(c,0,sizeof(c));
    memset(use,0,sizeof(use));
    cin>>n>>m;
    int a,b;
    while(m--){
        cin>>a>>b;
        c[a][b]=c[b][a]=1;
    }

    cout<<way(1,n,n);

    return 0;
}
