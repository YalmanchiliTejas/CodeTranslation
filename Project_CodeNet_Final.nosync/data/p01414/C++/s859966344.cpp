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
const int INF=100000000;

// eXªwè³ê½FÉÈéÜÅÌÅ¬X^vñ
int dp[1<<16];
char field[5][5];
vector<pair<int,int> > stumps;
int n;

char color[]={'R','G','B'};

int dfs(int s){
    if(s==0)
        return 0;
    if(dp[s]!=INF)
        return dp[s];
    int cnt=INF;
    // TCYÒÁ½è ¤êðIñÅX^vðßµÄ¢­
    for(int k = 0; k < stumps.size(); k++){
        int h=stumps[k].first;
        int w=stumps[k].second;
        // ¶ãÌÀWðè
        for(int i = -h+1; i < 4; i++){
            for(int j = -w+1; j < 4; j++){
                int ns=s;
                bool first=false;
                bool b=false;
                char cc=0;
                // Iñ¾ÍÍªS¯¶FÅ é©Ç¤©ð`FbN·é
                for(int k = i; k<min(i+h,4); k++){
                    for(int l = j; l < min(j+w,4); l++){
                        if(!(k>=0&&l>=0&&k<4&&l<4))
                            continue;
                        // hçêÄ¢éêÌÝl¶·é
                        if((s>>(k*4+l))&1){
                            if(!first){
                                cc=field[k][l];
                                first=true;
                            }
                            else{
                                if(field[k][l]==cc){
                                    //ok
                                }
                                else{
                                    b=true;
                                    break;
                                }
                            }
                        }
                    }
                    if(b)
                        break;
                }
                // SðÅ«éê,hèÂÔµððµÄAÄA
                if(!b&&first){
                    for(int k = i; k<min(i+h,4); k++){
                        for(int l = j; l < min(j+w,4); l++){
                            if(!(k>=0&&l>=0&&k<4&&l<4))
                                continue;
                            ns&=~(1<<(k*4+l));
                        }
                    }
                    cnt=min(cnt,dfs(ns)+1);
                }
            }
        }
    }
    return dp[s]=cnt;
}

void solve(){
    fill(dp,dp+(1<<16),INF);
    cin>>n;
    int h,w;
    for(int i = 0; i < n; i++){
        cin>>h>>w;
        stumps.push_back(make_pair(h,w));
    }
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            cin>>field[i][j];
    cout<<dfs((1<<16)-1)<<endl;
}
int main(){
    solve();
    return 0;
}