#include<iostream>
#include<cstdio>
#define MAX_INT 1 << 14
using namespace std;


int main(){
    bool dx[MAX_INT][40] = {false}, flag[40] = {false};
    int no, n;
    while(scanf("%d,%d", &no, &n)){
        if(no == 0 && n == 0) break;
        dx[no][n] = true;
        if(!flag[n]) flag[n] = true;
    }
    int num;
    while(cin >>num){
        int ans = 0;
        for(int i = 30; i >= 0; i--){
            if(flag[i]){
                ans++;
                if(dx[num][i]) break;
            }
        }
        cout <<ans <<endl;
    }
    return 0;
}