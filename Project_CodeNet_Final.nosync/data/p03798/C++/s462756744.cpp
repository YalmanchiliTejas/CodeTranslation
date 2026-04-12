#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<set>
#include<utility>
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> pipii;
typedef long long ll;
typedef pair<ll,ll> pll;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=100000;
const int MAXE=100000;
const int MAXV=10000;
const ll INF=2e18;
const ll MOD=1e9+7;
struct edge{
    int to;
    int cost;
};

int main(){
    int N;
    string S;
    cin>>N>>S;
    S+=S[0];
    for(int i=0;i<2;++i){
        for(int j=0;j<2;++j){
            string A="";
            A+=(i==0?'S':'W');
            A+=(j==0?'S':'W');
            for(int k=1;k<=N;++k){
                if((S[k]=='o'&&A[k]=='S')
                ||(S[k]=='x'&&A[k]=='W')){
                    if(A[k-1]=='S') A+='S';
                    else A+='W';
                }else{
                    if(A[k-1]=='S') A+='W';
                    else A+='S';
                }
            }
            if(A[0]==A[N]&&A[1]==A[N+1]){
                for(int k=0;k<N;++k){
                    cout<<A[k];
                }
                cout<<endl;
                return 0;
            }
        }
    }
    cout<<-1<<endl;
    return 0;
}

