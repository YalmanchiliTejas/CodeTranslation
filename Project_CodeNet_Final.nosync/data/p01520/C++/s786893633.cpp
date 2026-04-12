#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<cctype>
#include<complex>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<functional>
#include<utility>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>
 
using namespace std;
const int dx[] = {1,0,-1,0},dy[] = {0,1,0,-1};
#define INF 1e+9
#define EPS 1e-9
#define rep(i,j) for(int i = 0; i < (j); i++)
#define reps(i,j,k) for(int i = j; i < (k); i++)
typedef long long ll;
int n,t,e;
bool check(int x){
    int cnt = 1;
    int y = x;
    vector<int> data;
    reps(i,t-e,t+e+1)data.push_back(i);
    int len = data.size();
    while(true){
        if(y > data[len-1])break;
        rep(i,len)if(y == data[i])return true;
        cnt++;
        y=x*cnt;
    }
    return false;
}
int main(){
    scanf("%d%d%d",&n,&t,&e);
    bool f = false;
    rep(i,n){
        int x;
        scanf("%d",&x);
        if(check(x)){
            printf("%d\n",i+1);
            f = true;
            break;
        }
    }
    if(!f)printf("-1\n");
    return 0;
}