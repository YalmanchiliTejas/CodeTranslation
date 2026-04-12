#include<bits/stdc++.h>
using namespace std;
int main(){
char graph[10][10];
int n,m;
int row[10];
memset(row,0,sizeof row);
cin>>n>>m;
getchar();
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>graph[i][j];
        if(graph[i][j]=='#')row[i]++;
    }
    getchar();
}
int ck=0;
int j=0,i=0;
while(i<n){
        int cnt=0;
    while(j<m){
        if(graph[i][j]=='.')
            break;
        if(graph[i][j]=='#')
        cnt++;
        j++;
    }
    j--;
//cout<<cnt<<" "<<row[i]<<""<<j<<endl;
if(cnt!=row[i])
    {
        ck=1;
        break;
    }
i++;
}
    if(ck)
        printf("Impossible\n");
    else
        printf("Possible\n");
        /*#include<bits/stdc++.h>
using namespace std;
char a[10][10];
int main(){
    int n,m;
    cin>>n>>m;
    int i,j;
    int c1=0,c2=0;
    for(i=1;i<=n;i++)for(j=1;j<=m;j++){
            cin>>a[i][j];
            if(a[i][j]=='#')c1++;
    }
    //if(a[1][1]=='.')cout<<"Impossible"<<endl;
    for(i=1,j=1;j<=m && i<=n;){
        //cout<<j<<' ';
        if(a[i][j]=='#'){
            //cout<<1<<' ';
            c2++;
            j++;
        }
        else {
            //cout<<j<<' ';
            i++;
            j--;
        }
    }
    j--;
    cout<<i<<' '<<j<<endl;
    cout<<c1<<' '<<c2<<endl;
    if(c1==c2 && i==n && j==m)cout<<"Possible"<<endl;
    else cout<<"Impossible"<<endl;
}*/

}
