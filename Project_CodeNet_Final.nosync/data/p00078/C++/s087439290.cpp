#include <iostream>
#include <stdio.h>
#include <math.h>
#include <iomanip>

using namespace std;


int n;
int box[15][15];

bool magic(int x, int y, int num){
    if(num>n*n){
        return false;
    }
    if(x==n){
        return magic(0, y, num);
    }
    if(x==-1){
        return magic(n-1, y, num);
    }
    if(y==n){
        return magic(x, 0, num);
    }
    if(y==-1){
        return magic(x, n-1, num);
    }
    if(box[y][x]!=0){
       return  magic(x-1, y+1, num);
    }
    if(num<=n*n){
        box[y][x]=num;
        return magic(x+1, y+1, num+1);
    }
    
}



int main(void)
{
    while(cin>>n){
        if(n==0)break;
        for(int i=0; i<15; i++){
            for(int j=0; j<15; j++){
                box[i][j]=0;
            }
        }
        magic(n/2, n/2+1, 1);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<setw(4)<<right<<box[i][j];
                
            }
            cout<<endl;
        }
        
    }
    
}