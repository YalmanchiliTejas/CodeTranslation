#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;


int main(){
    int n,dice[7]={0,1,2,3,4,5,6},sum=1;
    char order[6];
    
    while(1){
        scanf("%d",&n);
        if(n==0) break;
        sum=1;
        for(int i=0;i<7;i++)
            dice[i]=i;
        
        for(int i=0;i<n;i++){
            scanf("%s",order);
            
            switch(order[0]){
                case 'N' :
                    dice[0]=dice[1];
                    dice[1]=dice[2];
                    dice[2]=dice[6];
                    dice[6]=dice[5];
                    dice[5]=dice[0];
                    break;
                case 'E' :
                    dice[0]=dice[1];
                    dice[1]=dice[4];
                    dice[4]=dice[6];
                    dice[6]=dice[3];
                    dice[3]=dice[0];
                    break;
                case 'W' :
                    dice[0]=dice[1];
                    dice[1]=dice[3];
                    dice[3]=dice[6];
                    dice[6]=dice[4];
                    dice[4]=dice[0];
                    break;
                case 'S' :
                    dice[0]=dice[1];
                    dice[1]=dice[5];
                    dice[5]=dice[6];
                    dice[6]=dice[2];
                    dice[2]=dice[0];
                    break;
                case 'R' :
                    dice[0]=dice[2];
                    dice[2]=dice[3];
                    dice[3]=dice[5];
                    dice[5]=dice[4];
                    dice[4]=dice[0];
                    break;
                case 'L' :
                    dice[0]=dice[2];
                    dice[2]=dice[4];
                    dice[4]=dice[5];
                    dice[5]=dice[3];
                    dice[3]=dice[0];
                    break;
            }
            sum += dice[1];
        }
        printf("%d\n",sum);
    }
    return 0;
    
}