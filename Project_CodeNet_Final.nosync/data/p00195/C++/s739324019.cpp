#include <bits/stdc++.h>

using namespace std;

int solve(){
    vector<int> p(5,0);
    int t;
    for (int i = 0; i < 10; ++i) {
        cin>>t;
        if(i==1&&t==0)return 1;
        p[i/2]+=t;
    }
    int ans=0;
    int ansn=-1;
    for (int i = 0; i < 5; ++i) {
        if(ans<p[i]){
            ans=p[i];
            ansn=i;
        }
    }
    auto ansc= static_cast<char>('A' + ansn);
    cout<<ansc<<" "<<ans<<endl;
    return 0;
}

int main(){
    while(solve()==0);
    return 0;
}
