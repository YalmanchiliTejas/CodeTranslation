#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using ll = long long;
using vl = vector<ll>;
using vpll = vector<pair<ll,ll>>;

int main() {
    bool flag1,flag2;
    ll N,M,count=0;
    cin>>N>>M;
    vl path(N);
    vpll path_list(M);
    rep(i,N){
        path[i]=i;
    }
    rep(i,M){
        cin>>path_list[i].first>>path_list[i].second;

    }
do{ 
    if(path[0]!=0){
        break;
    }
    
    flag1 = true;
    rep(i,N-1){
    flag2 = false;
    if(path[i]>path[i+1]){
        rep(j,M){
            if((path_list[j].second == path[i]+1)&&(path_list[j].first == path[i+1]+1)){
                flag2=true;
            }
        }

    }
    else{
        rep(j,M){
            if((path_list[j].first == path[i]+1)&&(path_list[j].second == path[i+1]+1)){
                flag2=true;
            }
    }
    
    }
    if(!flag2){
        flag1 = false;
        break;
    }
    
    }



if(flag1){
    count++;
}



}while(next_permutation(path.begin(),path.end()));

cout<<count<<endl;
}
