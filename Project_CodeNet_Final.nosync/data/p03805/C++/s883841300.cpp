#include<map>
#include<iostream>
#include<deque>
#include<algorithm>
#include<string>
#include<cctype>
#include<iomanip>
#include<vector>
#include<queue>
 
using namespace std;
#define REP(i,b,e) for(int i=(int)b;i<(int)e;i++)
#define rep0(i,n) REP(i,0,n)
#define rep1(i,n) REP(i,1,n+1)

#define shosu setprecision(10)

typedef long long ll;
ll longinf=1ll<<60;
int inf=1<<29;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};



int N,M;
int ans;
bool c[9][9];


int main(){
    cin>>N>>M;
    rep0(i,M){
        int a,b;
        cin>>a>>b;
        c[a-1][b-1]=c[b-1][a-1]=true;
    }
    vector<int> v;
    rep1(i,N-1){
        v.push_back(i);
    }
    do{
        bool ok=true;
        if(!c[0][v[0]])ok=false;
        rep0(i,N-2){
            if(!c[v[i]][v[i+1]]) ok=false;
        }
        if(ok) ans++;

    }while(next_permutation(v.begin(),v.end()));
    cout<<ans<<endl;
    return 0;
}