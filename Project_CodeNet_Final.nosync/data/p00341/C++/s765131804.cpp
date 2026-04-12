#include<bits/stdc++.h>
#define V vector
#define VI vector<int>
#define VVI vector<vector<int>>
#define rep(i,n) for(int i=0;i<(n);i++)
#define MOD 1000000007


using namespace std;

int main(void){
    VI E(12);
    rep(i,12)cin>>E[i];
    sort(E.begin(),E.end());
    if(E[0]==E[3]&&E[4]==E[7]&&E[8]==E[11]){
        cout<<"yes"<<endl;
        return 0;
    }
    cout<<"no"<<endl;
}


