#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <complex>
#include <iterator>
#include <cstdlib>
#include <cstring>
#include <sstream>

using namespace std;

#define EPS (1e-10)
#define EQ(a,b) (abs((a) - (b)) < EPS)
#define EQV(a,b) (EQ((a).real(),(b).real()) && EQ((a).imag(),(b).imag()))

typedef complex<double> P;
typedef long long ll;

const int MAX_SIZE = 10000;

char field[51][51];
int onCost[51][51];
int offCost[51][51];
int cnCost[51][51];
vector<int> passTime[51][51];
vector<pair<int,int> > works;

const int INF=1000000000;
const int dy[]={-1,0,0,1};
const int dx[]={0,-1,1,0};

int h,w,m;
pair<int,int> roots[5000];
int idx;
bool ok;

int vis[51][51];

int sumT=0;
bool passed[51][51];

void dfs(int x,int y,int gx,int gy,int depth){
    if(ok)
        return;
    if(passed[y][x])
        return;
    passed[y][x]=true;
    if(gx==x&&gy==y){
        roots[idx].first=gy;
        roots[idx].second=gx;
        idx++;
        sumT+=depth;
        for(int i = 0; i < idx; i++)
            passTime[roots[i].first][roots[i].second].push_back(sumT-idx+i+1);
        idx--;
        ok=true;
        passed[y][x]=false;
        return;
    }
    for(int i = 0; i < 4; i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(ny>=0&&nx>=0&&ny<h&&nx<w&&!passed[ny][nx]&&field[ny][nx]!='#'){
            roots[idx].first=y;
            roots[idx].second=x;
            idx++;
            dfs(nx,ny,gx,gy,depth+1);
            if(ok){
                idx--;
                passed[y][x]=false;
                return;
            }
            idx--;
        }
    }
    passed[y][x]=false;
}


int dp[10001][2];
// ÄAÆ»ÅÅ¬RXgðvZ
// schÍCgªÂ¢Ä¢é©¢È¢©
int calcMinCost(int place,int y,int x,int sch){
    if(dp[place][sch]!=INF)
        return dp[place][sch];
    if(place==0){
        if(sch)
            return onCost[y][x];
        else
            return onCost[y][x]+offCost[y][x];
    }
    else{
        if(passTime[y][x][place]==passTime[y][x][place-1])
            return calcMinCost(place-1,y,x,sch);
        int minCost=INF;
        // »ÝÂ¢Ä¢éê
        if(sch){
            // X[pXÈçÛRXg¾¯©©é
            minCost=min(minCost
                ,calcMinCost(place-1,y,x,1)+cnCost[y][x]*(abs(passTime[y][x][place]-passTime[y][x][place-1])));
            // ±±ÅÂ¯é¾¯
            minCost=min(minCost,calcMinCost(place-1,y,x,0)+onCost[y][x]);
        }
        else{
            // Â¯é
            minCost=min(minCost,calcMinCost(place-1,y,x,0)+onCost[y][x]+offCost[y][x]);
            // ¯·BºÌóÔ©çÌÛRXgªà¥¤
            minCost=min(minCost,calcMinCost(place-1,y,x,1)+offCost[y][x]+
                cnCost[y][x]*(abs(passTime[y][x][place]-passTime[y][x][place-1])));
        }
        return dp[place][sch]=minCost;
    }
}

void solve(){

    memset(vis,0,sizeof(vis));
    cin>>h>>w>>m;
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            cin>>field[i][j];
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            cin>>cnCost[i][j];
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            cin>>onCost[i][j];
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            cin>>offCost[i][j];
    for(int i = 0; i < m; i++){
        int x,y;
        cin>>y>>x;
        works.push_back(make_pair(y,x));
    }
    // »ê¼êÌÀW
    pair<int,int> cp=works[0];
    sumT=0;
    for(int i = 1; i < works.size(); i++){
        idx=0;
        ok=false;
        memset(passed,0,sizeof(passed));
        dfs(cp.second,cp.first,works[i].second,works[i].first,0);
        cp=works[i];
    }
    int sumCost=0;
    // ñxÊÁÄ¢éêÉÂ¢Äl@
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            for(int k = 0; k < 10001; k++)
                dp[k][0]=dp[k][1]=INF;
            sumCost+=calcMinCost(passTime[i][j].size()-1,i,j,0);
        }
    }
    cout<<sumCost<<endl;
}
int main(){
    solve();
    return 0;
}