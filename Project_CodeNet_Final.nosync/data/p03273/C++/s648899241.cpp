#include<bits/stdc++.h>
using namespace std;
char a[1000][1000],b[1000][1000],y[1000][1000];
int main(){
int n,m;
cin>>n>>m;
string x,s;
bool ok=0;
for(int i=0;i<n;i++){
for(int j=0;j<m;j++){
    cin>>a[i][j];
  }
}
int c=0;
for(int i=0;i<n;i++){
    ok=0;
   for(int j=0;j<m;j++){
        if(a[i][j]=='#'){
            ok=1;break;
        }
    }
    if(ok==1){
     for(int k=0;k<m;k++)b[c][k]=a[i][k];
     c++;
    }
}int h=0;
for(int i=0;i<m;i++){
    ok=0;
    for(int j=0;j<c;j++){
   if(b[j][i]=='#'){
       ok=1;break;
   }
    }
 if(ok==1){
     for(int k=0;k<m;k++)y[k][h]=b[k][i];
     h++;
    }
}
for(int i=0;i<c;i++){
    for(int j=0;j<h;j++){
    cout<<y[i][j];
}
cout<<"\n";
}
		return 0;
}