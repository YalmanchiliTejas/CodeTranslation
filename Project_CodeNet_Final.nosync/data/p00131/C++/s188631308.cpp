#include<string>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<complex>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#include<sstream>
#include<iostream>
using namespace std;
int field[10][10];
bool greed(string top){
    int a[10][10];
    int ans[10][10];
    for(int i = 0;i < 10;i++){
        for(int j = 0;j < 10;j++){
            ans[i][j] = 0;
        }
    }
    for(int i = 0;i < 10;i++){
        for(int j = 0;j < 10;j++){
            a[i][j] = field[i][j];
        }
    }
    for(int j = 0;j < 10;j++){
        if(top[j]=='1'){
            ans[0][j] = 1;
            a[0][j] = 1 - a[0][j];
            if(j!=0)a[0][j-1] = 1 - a[0][j-1];
            if(j!=9)a[0][j+1] = 1 - a[0][j+1];
            a[1][j] = 1 - a[1][j];
        }
    }
    for(int i = 1;i < 10;i++){
        for(int j = 0;j < 10;j++){
            if(a[i-1][j]==1){
                ans[i][j] = 1;
                a[i][j] = 1 - a[i][j];
                if(i!=9)a[i+1][j] = 1 - a[i+1][j];
                if(j!=9)a[i][j+1] = 1 - a[i][j+1];
                if(i!=0)a[i-1][j] = 1 - a[i-1][j];
                if(j!=0)a[i][j-1] = 1 - a[i][j-1];
            }
        }
    }
    bool flg = false;
    for(int j = 0;j < 10;j++){
        if(a[9][j]==1){
            flg = true;
            break;
        }
    }
    if(!flg){
        for(int i = 0;i < 10;i++){
            cout<<ans[i][0];
            for(int j = 1;j < 10;j++){
                cout<<" "<<ans[i][j];
            }
            cout<<endl;
        }
        return true;
    }
    else return false;
}
int cnt;

void perm(int dep,string top){
    if(dep == 10){
        greed(top);

        return;
    }
    perm(dep + 1,top);
    top[dep] = '1';
    perm(dep + 1,top);
}
int main(void){

    int n;
    cin>>n;
    while(n--){
        for(int i = 0;i < 10;i++)
            for(int j = 0;j < 10;j++)
                cin>>field[i][j];

        perm(0,"0000000000");
    }


    return 0;
}