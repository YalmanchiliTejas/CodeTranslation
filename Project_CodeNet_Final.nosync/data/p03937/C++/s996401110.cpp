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
}
