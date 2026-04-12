#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int I[]={0,1};
int J[]={1,0};

int H,W;
char A[8][8];
int chk[8][8];

int main(){
    cin>>H>>W;
    rep(i,H) rep(j,W) cin>>A[i][j];

    queue<P> q;
    q.push(P(0,0));
    chk[0][0]=1;
    bool flag=false;
    while(!q.empty()){
        P p=q.front(); q.pop();
        if(p.first==H-1 && p.second==W-1){
            flag=true;
            break;
        }
        rep(k,2){
            int i=p.first+I[k];
            int j=p.second+J[k];
            if(i<=H && j<=W && A[i][j]=='#' && chk[i][j]==0){
                chk[i][j]=1;
                q.push(P(i,j));
            }
        }
    }

    if(!flag){
        cout<<"Impossible"<<endl;
        return 0;
    }

    int sum=0;
    rep(i,H){
        rep(j,W){
            if(A[i][j]=='#') sum++;
        }
    }

    string ans=sum==H+W-1?"Possible":"Impossible";
    cout<<ans<<endl;
}