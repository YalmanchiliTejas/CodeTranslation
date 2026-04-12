#include <bits/stdc++.h>
using namespace std;
 typedef long long ll;
 
int main() {
int h,w;
cin>>h>>w;
char m[110][110];
for(int i=1;i<=h;i++){
for(int j=1;j<=w;j++){
cin>>m[i][j];
}
}

for(int i=1;i<=h;i++){
    bool c=1;
for(int j=1;j<=w;j++){
if(m[i][j]=='#')c=0;
}
if(c)m[i][0]='n';
}
for(int j=1;j<=w;j++){
    bool c=1;
for(int i=1;i<=h;i++){
if(m[i][j]=='#')c=0;
}
if(c)m[0][j]='n';
}
for(int i=1;i<=h;i++){
if(m[i][0]!='n'){
for(int j=1;j<=w;j++){
if(m[0][j]!='n')cout<<m[i][j];
}
}
if(m[i][0]!='n')cout<<endl;
}
 
 
}