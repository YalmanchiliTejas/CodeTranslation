#include <bits/stdc++.h>
using namespace std;
int main(){
int H,W;
cin>>H>>W;
char a[H][W];
for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
        cin>>a[i][j];
    }
}
int cnt=0;
string x;
for(int i=0;i<H;i++){
   for(int j=0;j<W;j++){
        if(a[i][j]=='.'||a[i][j]=='*')cnt++;
    }
    if(cnt==W){
       for(int j=0;j<W;j++){
        a[i][j]='*';
    }

    }
    cnt=0;
}
cnt=0;
for(int i=0;i<W;i++){
   for(int j=0;j<H;j++){
        if(a[j][i]=='.'||a[j][i]=='*')cnt++;
    }
    if(cnt==H){
       for(int j=0;j<H;j++){
        a[j][i]='*';
    }

    }
    cnt=0;
}
bool b=false;
for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
        if(a[i][j]!='*'){
        cout<<a[i][j];
        b=true;
        }
        if(j==W-1&&b)cout<<endl;
    }
    b=false;

}

return 0;
}