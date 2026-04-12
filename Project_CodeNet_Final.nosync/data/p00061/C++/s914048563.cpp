#include<iostream>
#include<string.h>
#include<vector>
#include<list>
#include<stdio.h>
#include<math.h>
#include<iomanip>
#include<map>
#include<stack>
#include<queue>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) range(i,0,b)
#define debug(x) cout << "debug " << x << endl;
using namespace std;

struct info{
    int n;
    int p;
    int r;
};

int main(){
    int k = 0;
    struct info inp[105];
    while(scanf("%d%*c%d",&inp[k].n, &inp[k].p), inp[k].n||inp[k].p) k++;
    rep(i,k){
        rep(j,k){
            if(inp[j].p < inp[j + 1].p){
                struct info g = inp[j]; inp[j] = inp[j + 1]; inp[j + 1] = g;
            }
        }
    }
    int rank = 1;
    rep(i,k){
        inp[i].r = rank;
        if(inp[i].p != inp[i + 1].p) rank++;
    }
    int inr;
    while(cin >> inr){
        rep(i, k){
            if(inp[i].n == inr)
                cout << inp[i].r << endl;
        }
    }
}