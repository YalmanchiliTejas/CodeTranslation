#include<stdio.h>
#include<bits/stdc++.h>


#define             si(a)                   scanf("%d",&a)
#define             sii(a,b)                scanf("%d%d",&a,&b)
#define             siii(a,b,c)             scanf("%d%d%d",&a,&b,&c)
#define             fr(i,n)                 for(int i=0;i<n;i++)
#define             bl                      printf("\n")
#define             inf                     1000000
#define             sz                      110

using namespace std;

char grid[sz][sz];

int main(){
    int h,w,cnt=0;

    sii(h,w);

    fr(i,h){

     scanf("%s",grid[i]);

    }


    fr(i,h){
        fr(j,w){
            if(grid[i][j]=='.') cnt++;
        }

        if(cnt==w){
            fr(k,w) grid[i][k] = 'd';
        }
        cnt = 0;
    }


    fr(i,w){
        fr(j,h){
            if(grid[j][i]=='.' || grid[j][i]=='d') cnt++;
        }

        if(cnt==h){
            fr(k,h) grid[k][i] = 'd';
        }
        cnt = 0;
    }

    fr(i,h){
        fr(j,w){
            if(grid[i][j] !='d'){
                printf("%c",grid[i][j]);
                cnt++;
            }
        }
        if(cnt>0)bl;
        cnt=0;
    }

    return 0;
}
