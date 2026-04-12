#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
bool e[10][10];
int m,n;
int ar[8]={1,2,3,4,5,6,7,8};
bool has(){
rep(i,n-1)if(!e[ar[i]][ar[i+1]])return 0;
return 1;
}
int main(){
cin>>n>>m;
rep(i,m){
int a,b;
cin>>a>>b;
e[a][b]=e[b][a]=1;
}
int ans=0;
do{
if(has())ans++;
}while(next_permutation(ar+1,ar+n));
cout<<ans<<endl;
return 0;
}