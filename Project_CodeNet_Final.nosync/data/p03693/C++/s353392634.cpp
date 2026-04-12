#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);i++)
const int MOD=(int)1e9+7;
using namespace std;
int main(){
    int r,g,b;
    cin>>r>>g>>b;
    if((r*100+g*10+b)%4 == 0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}