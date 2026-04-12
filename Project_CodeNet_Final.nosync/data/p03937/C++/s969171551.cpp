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
typedef pair<int,int> P;


char board[50][50];

int main(void){
    int h,w;
    cin>>h>>w;
    int num = 0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>board[i][j];
            if(board[i][j]=='#')num++;
        }
    }
    if(num!=h+w-1)cout<<"Impossible"<<endl;
    else cout<<"Possible"<<endl;
    return 0;
}