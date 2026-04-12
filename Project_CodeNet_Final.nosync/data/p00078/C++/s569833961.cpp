#include<cstdio>
#include<iostream>
using namespace std;

int main(){
    
    int n,x,y;
    
    while(cin >> n,n!=0){
        int masu[20][20]={};
        x = n/2;
        y = n/2+1;
        for(int i=1;i<=n*n;i++){
            masu[y][x] = i;
            x=(x+1)%n;
            y=(y+1)%n;
            if(masu[y][x] != 0){
                x=(x-1+n)%n;
                y=(y+1)%n;
            }
        }
    
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                printf("%4d",masu[i][j]);
            }
            cout << endl;
        }
    }
    
    return(0);
}
