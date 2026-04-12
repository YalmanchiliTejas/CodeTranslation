#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll,ll> P;

vector<int> v[8];
int n,m;

int ma(int now,int d){
    if(d==((1<<n)-1)){
        return 1;
    }
    int ans=0;
    for(auto itr:v[now]){
        if(d&(1<<itr)){
        }else{
            ans+=ma(itr,d|(1<<itr));
        }
    }
    return ans;
}

int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cout<<ma(0,1)<<endl;

    return 0;
}