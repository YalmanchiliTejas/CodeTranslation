#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

typedef long long ll;
const int MAX=1e5+10;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
const int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

bool Check(int k,const int l,const string& s,char* ans){
    if(k>1){
        if(ans[k-1]=='S'&&(s[k-1]=='o'^ans[k-2]==ans[k])||ans[k-1]=='W'&&(s[k-1]=='o'^ans[k-2]!=ans[k]))
            return false;
        if(k==l-1){
            for(int i=0;i<2;i++){
                if(ans[(k+i+l)%l]=='S'&&(s[(k+i+l)%l]=='o'^ans[(k+i-1+l)%l]==ans[(k+i+1+l)%l])||ans[(k+i+l)%l]=='W'&&(s[(k+i+l)%l]=='o'^ans[(k+i-1+l)%l]!=ans[(k+i+1+l)%l]))
                    return false;
            }
        }
    }
    return true;
}

void solve(int depth,const int l,const string& s,bool& f,char* ans,const string& t){
    if(depth==l){
        f=true;
        return;
    }
    for(int i=0;i<2;i++){
        ans[depth]=t[i];
        if(Check(depth,l,s,ans)){
            solve(depth+1,l,s,f,ans,t);
            if(f) return;
        }
    }
}

int main(){
    int l;
    string s,t="SW";
    while(cin>>l>>s){
        bool f=false;
        char ans[100002]={0};
        solve(0,l,s,f,ans,t);
        if(f) puts(ans);
        else puts("-1");
    }
    return 0;
}
