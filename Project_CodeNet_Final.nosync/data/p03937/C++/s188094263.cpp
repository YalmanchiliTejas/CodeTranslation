//#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
//using namespace atcoder;
typedef long long ll;
typedef pair<ll,ll> P;
const ll MOD=1000000007;
int h,w;
char c[10][10];
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>h>>w;
    int cnt=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>c[i][j];
            if(c[i][j]=='#') cnt++;
        }
    }
    if(cnt==h+w-1){
        cout<<"Possible"<<endl;
    }else{
        cout<<"Impossible"<<endl;
    }
    
}
