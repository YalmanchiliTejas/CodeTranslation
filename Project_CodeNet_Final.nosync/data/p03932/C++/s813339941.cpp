#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <cstring>
#include <math.h>
#include <bitset>
#include <time.h>
#include <set>
#include <algorithm>
#define ll long long
using namespace std;

ll A[222][222];
ll dp[222][222][222];


ll Solve(int x1,int y1,int x2,int y2,int H,int W) {
    if (x1==H && y1==W)
        return A[H][W];
    
    
    if (dp[x1][y1][x2]!=-1)
        return dp[x1][y1][x2];
    
    ll curr = A[x1][y1];
    if (x1 != x2)
        curr += A[x2][y2];

    ll retval = 0;
    
    for(int b1=0;b1<=1;b1++)
        for(int b2=0;b2<=1;b2++) {
            int nx1=x1;
            int ny1=y1;
            int nx2=x2;
            int ny2=y2;
            
            if (b1==0) {
                nx1++;
            } else {
                ny1++;
            }
            
            if (b2==0) {
                nx2++;
            } else {
                ny2++;
            }
            
            if (nx1 > H | ny1 > W || nx2 > H || ny2 > W)
                continue;
            retval = max(retval, curr+Solve(nx1,ny1,nx2,ny2,H,W));
        }
    return dp[x1][y1][x2]=retval;
    
    
}

int main() {
    int H,W;
    cin>>H>>W;
    for(int i=1;i<=H;i++)
        for(int j=1;j<=W;j++)
            cin>>A[i][j];
    
    for(int i=0;i<=H;i++)
        for(int j=0;j<=W;j++)
            for(int k=0;k<=H;k++)
                dp[i][j][k]=-1;
    cout << Solve(1,1,1,1,H,W) << endl;
    
}