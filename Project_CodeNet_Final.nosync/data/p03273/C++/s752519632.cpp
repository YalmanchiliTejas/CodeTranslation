#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout<< (x) << " "

int main(){
    int h,w;cin>>h>>w;
    string s[h];
    string tmp;
    int hflag[h]={0},wflag[w]={0};
    rep(i,h){
        cin>>s[i];
        bool is_sharp=false;
        rep(j,w){
            if(s[i][j]=='#'){wflag[j]++;is_sharp=true;}
        }
        if(is_sharp)hflag[i]++;
    }
    rep(i,h){
        if(hflag[i]==0){continue;}
        rep(j,w){
            if(wflag[j]>0)printf("%c",s[i][j]);
        }
        printf("\n");
    }
}