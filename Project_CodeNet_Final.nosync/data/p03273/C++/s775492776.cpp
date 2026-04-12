#include <bits/stdc++.h>
using namespace std;
bool mark[1000];
bool marv[1000];
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int n;
int m;
cin>>n>>m;
char v[n][m];
for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
                      cin>>v[i][j];
           }
}
int r=0;
for(int i=0;i<n;i++){
           r=0;
           for(int j=0;j<m;j++){
                      if(v[i][j]=='#'){
                                 j=m+2;
                                 r=1;
                      }
           }
           if(r==0){
                      mark[i]=true;
           }
           
}
for(int i=0;i<m;i++){
           r=0;
           for(int j=0;j<n;j++){
           if(v[j][i]=='#'){
                      j=n+2;
                      r=1;
           }           
           }
           if(r==0){
                      marv[i]=true;
           }
}
for(int i=0;i<n;i++){
           r=0;
           for(int j=0;j<m;j++){
                      if(mark[i]==false&&marv[j]==false){
                                 cout<<v[i][j];
                                 r=1;
                      }
           }
           if(r==1){
                      cout<<endl;
           }
}
return 0;
}