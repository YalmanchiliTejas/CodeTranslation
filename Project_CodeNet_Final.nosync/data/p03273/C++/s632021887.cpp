#include<bits/stdc++.h>
using namespace std;
int main(){
    int H,W;
    char a[101][101];
    int flag[101]={};
    int flag2[101]={};
    
    cin>>H>>W;
    for(int i=0;i<H;i++)
        for(int j=0;j<W;j++) cin>>a[i][j];
    
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(a[i][j]=='#'){
                flag[i]=1;
                break;
            }
        }
    }
    
    for(int j=0;j<W;j++){
        for(int i=0;i<H;i++){
            if(a[i][j]=='#'){
                flag2[j]=1;
                break;
            }
        }
    }
    
    for(int i=0;i<H;i++){
        if(!flag[i]) continue;
        for(int j=0;j<W;j++){
            if(!flag2[j]) continue;
            cout<<a[i][j];
        }
        cout<<endl;
    }
    return 0;
}

