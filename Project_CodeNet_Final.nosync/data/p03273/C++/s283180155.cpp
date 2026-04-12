#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
const int INF=1145141919,MOD=1e9+7;
const long long LINF=8931145141919364364,LMOD=998244353;
// const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};

int main(){
    int h,w; cin>>h>>w;
    vector<string> s;
    int hh=h;
    rep(i,h){
        string ss; cin>>ss;
        bool flg=1;
        for(char c:ss){
            if(c=='#') flg=0;
        }
        if(flg){
            hh--;
        }else{
            s.push_back(ss);
        }
    }
    vector<int> wnum;
    rep(i,w){
        bool flg=1;
        rep(j,hh){
            if(s[j][i]=='#') flg=0;
        }
        if(!flg){
            wnum.push_back(i);
        }
    }
    rep(i,hh){
        for(auto j:wnum){
            cout<<s[i][j];
        }
        cout<<endl;
    }
    return 0;
}
