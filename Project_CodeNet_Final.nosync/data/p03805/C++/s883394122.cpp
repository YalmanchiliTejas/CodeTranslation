#include<bits/stdc++.h>
using namespace std;
int n,m,res;
vector<vector<int>> d(8);
string L;

void dfs(int i,string s,int p=0){
    if(i==n-1){
        //cout<<s<<" "<<L<<endl;
        if(s==L){
            res++;
            return;
        }
    }
    for(int j=0;j<d[p].size();j++){
        string ss = s;
        int x = d[p][j];
        if(ss[x]=='0'){
            ss[x]='1';
            dfs(i+1,ss,x);
            //cout<<ss<<endl;
        }
        
    }
    return;
}

int main(){
    cin>>n>>m;
    res=0;
    L="1";
    string sss = "1";
    for(int i=0;i<n-1;i++){
        L+="1";
        sss+="0";
    }
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;a--;b--;
        d[a].push_back(b);
        d[b].push_back(a);
    }
    dfs(0,sss);
    cout<<res<<endl;
}