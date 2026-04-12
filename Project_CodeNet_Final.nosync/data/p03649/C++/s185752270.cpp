#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> P;
const LL mod=1e9+7;
const LL LINF=1LL<<62;


int main(){
    int N;
    cin >> N;
    vector<LL> v;
    for(int i=0;i<N;i++){
        LL a;
        cin >> a;
        v.push_back(a);
    }
    LL ans=0;
    while(1){
        auto p=max_element(v.begin(),v.end());
        LL k=*p/N;
        *p%=N;
        for(int i=0;i<N;i++){
            if(i==p-v.begin()) continue;
            else v[i]+=k;
        }
        ans+=k;
        if(*max_element(v.begin(),v.end())<=N-1) break;
    }
    cout << ans << endl;
    return 0;
}