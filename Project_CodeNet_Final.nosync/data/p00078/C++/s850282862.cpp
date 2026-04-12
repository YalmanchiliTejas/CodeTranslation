#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

int m[16][16];
int main(){
    int n,y,x,cur;
    while(cin>>n,n){
        memset(m,0,sizeof(m));
        y=(n+1)/2;
        x=(n-1)/2;
        cur=1;
        m[y][x]=1;
        while(cur<n*n){
            y=(y+1)%n;
            x=(x+1)%n;
            cur+=1;
            while(m[y][x]>0){
                y=(y+1)%n;
                x=(x-1+n)%n;
            }
            m[y][x]=cur;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cout<<setfill(' ')<<setw(4)<<m[i][j];
            cout<<endl;
        }
    }
}