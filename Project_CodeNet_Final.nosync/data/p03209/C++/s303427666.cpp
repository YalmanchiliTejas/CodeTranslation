#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <utility>
#include <numeric>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <limits.h>
#define int long long
using namespace std;
using P = pair<int, int>;
using ll = long long;
using prique = priority_queue<int>;
const int MOD = 1000000007;
const int INF = LLONG_MAX/3;
int cnt(int level){
    return pow(2,level+2)-3;
}
int solve(int level,int x){
    if(level==0)return 1;
    else{
        if(x==1)return 0;
        else if(x<=cnt(level-1)+1)return solve(level-1,x-1);
        else if(x==cnt(level-1)+2)return solve(level-1,cnt(level-1))+1;
        else if(x<=cnt(level)-1)return solve(level-1,cnt(level-1))+1+solve(level-1,x-cnt(level-1)-2);
        else return 2*solve(level-1,cnt(level-1))+1;
    }
}
signed main(){
    int n,x;
    cin>>n>>x;
    cout<<solve(n,x)<<endl;
    return 0;
}
