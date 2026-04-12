
#include <numeric>
#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include<algorithm>
#include <sstream>
using namespace std;
long long inf=100000000000007;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
typedef pair<int,int>  P;
string alph("abcdefghijklmnopqrstuvwxyz");
struct edge{int to,cost;};
vector<edge> G[22];
vector<int> O[10];
char fi[1005][1005];
P sg[10];
int d[1005][1005];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
pair<int,double> s[1005];
int c=0;
int n,k;
signed main(){
    bool bo[10][10]={false};
    int n,m;cin>>n>>m;
    int a,b;
    rep(i,m){
        cin>>a>>b;
        bo[a][b]=true;
        bo[b][a]=true;
    }
    vector<int> v(n);
    int c=0,d=0;
    iota(v.begin(),v.end(),1);
    int count=0;
    do{
        bool s=true;
        for(auto x:v){
            d=c;
            c=x;
            if(c!=0&&d!=0){
                if(!bo[c][d])s=false;
            }
        }
        if(s)count++;
        c=0;d=0;
    }while(next_permutation(v.begin()+1, v.end()) );
    cout<<count<<endl;
    return 0;
}