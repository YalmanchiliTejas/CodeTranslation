#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000007
int main(){
    int H,W;
    cin>>H>>W;
    char a[H][W];
    for(int i=0;i<H;i++){
        cin>>a[i];
    }
    for(int k=0;k<W;k++){
        int count=0;
        for(int i=0;i<H;i++){

            if(a[i][k]=='.' or a[i][k]=='p')count++;

        }
        if(count==H){
            for(int i=0;i<H;i++){
                a[i][k]='p';
            }
        }
    }
    for(int k=0;k<H;k++){
        int count=0;
        for(int i=0;i<W;i++){

            if(a[k][i]=='.' or a[k][i]=='p')count++;

        }
        if(count==W){
            for(int i=0;i<W;i++){
                a[k][i]='p';
            }
        }
    }

    for(int i=0;i<H;i++){
        int count2=0;
        for(int k=0;k<W;k++){
            if(a[i][k]!='p'){
                cout<<a[i][k];
                count2++;
            }
        }
        if(count2>0)cout<<endl;
    }
    return 0;
}
