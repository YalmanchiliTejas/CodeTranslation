#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
using namespace std;
#define N (1000000000+7)
#define M (998244353)
#define INF 1e16
typedef long long ll;
typedef pair<ll,ll> P;

char board[105][105];

int main(void){
    int h,w;
    cin>>h>>w;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>board[i][j];
        }
    }
    for(int i=0;i<h;i++){
        int num = 0;
        for(int j=0;j<w;j++){
            if(board[i][j]!='#')num++;
        }
        if(num==w){
            for(int j=0;j<w;j++)board[i][j]='1';
        }
    }
    for(int j=0;j<w;j++){
        int num = 0;
        for(int i=0;i<h;i++){
            if(board[i][j]!='#')num++;
        }
        if(num==h){
            for(int i=0;i<h;i++)board[i][j]='1';
        }
    }
    for(int i=0;i<h;i++){
        bool flag = false;
        for(int j=0;j<w;j++){
            if(board[i][j]!='1')cout<<board[i][j],flag=true;
        }
        if(flag)cout<<endl;
    }
    return 0;
}