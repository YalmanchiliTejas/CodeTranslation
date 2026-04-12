#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int H,W; cin>>H>>W;
    vector<string> A(H);
    rep(h,0,H) cin>>A.at(h);

    vector<int> prjH,prjW;
    rep(h,0,H){
        bool allDot=true;
        rep(w,0,W){
            if(A.at(h).at(w)=='#'){allDot=false; break;}
        }
        if(!allDot){
            prjH.push_back(h);
        }
    }

    rep(w,0,W){
        bool allDot=true;
        rep(h,0,H){
            if(A.at(h).at(w)=='#'){allDot=false; break;}
        }
        if(!allDot){
            prjW.push_back(w);
        }
    }

    for(auto h:prjH){
        for(auto w:prjW) cout<<A.at(h).at(w);
        cout<<endl;
    }
}