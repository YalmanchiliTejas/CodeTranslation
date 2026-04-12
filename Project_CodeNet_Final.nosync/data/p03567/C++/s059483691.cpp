

#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include<algorithm>
using namespace std;
long long inf=100000000000007;
#define int long long
typedef pair<int,int>  P;
string alph("abcdefghijklmnopqrstuvwxyz");
struct edge{int to,cost;};
vector<edge> G[22];
char fi[1005][1005];
P sg[10];
int d[1005][1005];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int c=0;
int n,m,t;
signed main(){
    string s;cin>>s;
    bool a=false;
    for(int i=0;i<s.length();i++){
        if(s[i]=='A'&&s[i+1]=='C')a=true;
    }
    if(a)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
