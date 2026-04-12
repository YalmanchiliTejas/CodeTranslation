#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <array>
#include <set>
#include <climits>
#include <cassert>
#include <bitset>
#include <numeric>
using namespace std;
#define mod 1000000007
long long dp[102][5][2];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    string S;cin>>S;
    int K; cin>>K;
    dp[0][0][0]=1;
    for(int i=0;i<(int)S.size();++i)/*size of number we need*/{
        for(int j=0;j<=K;++j)/* non zero element selected*/{
            for(int k=0;k<2;++k)/* are we sure that number is less then N */{
                for(int l=0;l<10;++l){
                    int c =S[i]-'0';
                    if(k==0 && l>c)/* number is out of limit*/{
                        continue;
                    }
                    dp[i+1][j+(l>0)][k|(l<c)]+=dp[i][j][k];
                }
            }
        }
    }
    cout<<dp[(int)S.size()][K][0]+dp[(int)S.size()][K][1]<<endl;
    return 0;
}