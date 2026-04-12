#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <set>
#include <iomanip>
#include <deque>
#include <stdio.h>
using namespace std;

#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define RREP(i,n) for(int (i)=(int)(n)-1;i>=0;i--)
#define iREP(i,Itr) for(auto (i)=(Itr).begin();(i)!=(Itr).end();(i)++)
#define REMOVE(Itr,n) (Itr).erase(remove((Itr).begin(),(Itr).end(),n),(Itr).end())
#define PB_VEC(Itr1,Itr2) (Itr1).insert((Itr1).end(),(Itr2).begin(),(Itr2).end())
#define UNIQUE(Itr) sort((Itr).begin(),(Itr).end()); (Itr).erase(unique((Itr).begin(),(Itr).end()),(Itr).end())
#define LBOUND(Itr,val) lower_bound((Itr).begin(),(Itr).end(),(val))
#define UBOUND(Itr,val) upper_bound((Itr).begin(),(Itr).end(),(val))
typedef long long ll;

int h,w;
vector<string> M;

void dfs(int y, int x){
    M[y][x]='.';
    if(y+1<h){
        if(M[y+1][x]=='#'){
            dfs(y+1,x);
            return;
        }
    }
    if(x+1<w){
        if(M[y][x+1]=='#'){
            dfs(y,x+1);
            return;
        }
    }
}

int main(){
    cin>>h>>w;
    M.resize(h);
    REP(i,h)cin>>M[i];
    
    dfs(0,0);
    
    REP(i,h)REP(j,w){
        if(M[i][j]=='#'){
            cout<<"Impossible"<<endl;
            return 0;
        }
    }
    
    cout<<"Possible"<<endl;
    return 0;
}