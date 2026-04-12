#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<math.h>
using namespace std;
#define N (1000000000+7)
#define INF 1e16
typedef pair<int,int> P;
typedef long long ll;
int h,w;
char board[10][10];
bool used[10][10];
bool check(int i, int j) {
	return (i >= 1) && (i <= h) && (j >= 1) && (j <= w) && (board[i][j] == '#')&&(!used[i][j]);
}
bool dfs(int i,int j){
    if(i==h&&j==w){
        int num=0;
        if(check(i-1,j))num++;
        if(check(i,j-1))num++;

        if(num==0)return true;
        else return false;
    }
    int up=0,down=0,left=0,right=0;
    if(check(i+1,j))down++;
    if(check(i,j+1))right++;
    if(check(i-1,j))up++;
    if(check(i,j-1))left++;

    if((up!=0)||(left!=0))return false;
    else{
        if((down==1)&&(right==1))return false;
        else{
            if(down==1){
                used[i][j]=true;
                return dfs(i+1,j);
            }
            else{
                if(right==1){
                    used[i][j]=true;
                    return dfs(i,j+1);
                }
                else return false;
            }
        }
    }
}

int main(void){
    cin>>h>>w;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin>>board[i][j];
        }
    }
    if(dfs(1,1))cout<<"Possible"<<endl;
    else cout<<"Impossible"<<endl;
    return 0;
}