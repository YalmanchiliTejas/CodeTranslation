#include <bits/stdc++.h>
#include <ctype.h>
using namespace std;
 
 
int main(){
    long H,W;
    cin>>H>>W;
    char a[H][W];
    int b=0,d=0;
    bool f[H],g[W];
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin>>a[i][j];
            if(a[i][j]=='.')b++;
        }
        if(b==W)f[i]=0;
        else f[i]=1;
        b=0;
    }

    for(int i=0;i<W;i++){
        for(int j=0;j<H;j++){
            if(a[j][i]=='.')d++;
        }
        if(d==H)g[i]=0;
        else g[i]=1;
        d=0;
    }
    for(int i=0;i<H;i++){
        if(f[i]){
            for(int j=0;j<W;j++){
                if(g[j])cout<<a[i][j];
            }
            cout<<endl;
        }
    }

}