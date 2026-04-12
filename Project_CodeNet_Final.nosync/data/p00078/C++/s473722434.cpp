#include<iostream>
#include<utility>
#include<vector>
#include<cstdio>
using namespace std;
void check();
void syoki();
#define DEBUG for(int i=1;i<=n;i++){for(int j=1;j<=n;j++){cout<<square[j][i]<<" ";}cout<<endl;}
int n,add=2;
    pair<int,int> ad;//x,y
vector<vector<int> >square(20,vector<int>(20,-1)) ;
int main(){
    while(1){
        cin>>n;
        if(n==0){
            break;
        }
        ad.first=n/2+1;
        ad.second=n/2+2;
        square[ad.first][ad.second]=1;
        while(1){
            if(add==n*n+1)break;
            add+=1;
            ad.first+=1;
            ad.second+=1;
            check();
            if(square[ad.first][ad.second]!=-1){
                ad.first-=1;
                ad.second+=1;
                check();
                square[ad.first][ad.second]+=add;
            }
            else{
                square[ad.first][ad.second]+=add;
            }
        }
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(j==n && i==n){
                        printf("%4d",square[j][i]);
                    }
                    else{
                        printf("%4d",square[j][i]);
                    }
                }cout<<endl;
            }
        syoki();
    }
    return 0;
}
void check(){
    if(ad.first>n){
                ad.first=1;
            }
            if(ad.first<=0){
                ad.first=n;
            }
            if(ad.second>n){
                ad.second=1;
            }
    return ;
}
void syoki(){
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            square[i][j]=-1;
        }
    }
    add=2;
    return ;
}