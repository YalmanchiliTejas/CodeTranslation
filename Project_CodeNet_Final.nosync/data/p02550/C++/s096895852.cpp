#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    long long x,m;
    cin>>n>>x>>m;

    //出てきた余りを記録
    vector<int> mod;
    //繰り返しの最初のインデックスを保持
    vector<int> idx(m,-1);
    long long a = x;
    int count = 0;
    
    while(idx[a]==-1){
        idx[a] = count;
        mod.push_back(a);
        count++;
        if(count==n) break;
        x = a;
        a = (x*x) %m;
    }


    long long ans = 0;
    //繰り返されない部分の和
    for(int i=0;i<=idx[a]-1;i++){
        ans += mod[i];
    }
    //繰り返す部分
    //countはmodの長さ
    long long repeated = 0;
    for(int i=idx[a];i<count;i++){
        repeated += mod[i];
    }
    ans += repeated*((n-idx[a])/(count-idx[a]));
    if((n-idx[a])/(count-idx[a])){
        for(int i=0;i<(n-idx[a])%(count-idx[a]);i++){
            ans += mod[idx[a]+i];
        }
    }

    cout<<ans<<endl;
    
    return 0;
}