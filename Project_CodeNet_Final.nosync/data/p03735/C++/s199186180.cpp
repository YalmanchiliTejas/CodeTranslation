#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long int> x(n),y(n);
    long long int ma=0;
    long long int mi=1e9+1;
    long long int mima=0;
    long long int mami=1e9+1;
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
        ma=max({ma,x[i],y[i]});
        mi=min({mi,x[i],y[i]});
        mima=max(mima,min(x[i],y[i]));
        mami=min(mami,max(x[i],y[i]));
    }
    long long int res=(ma-mami)*(mima-mi);
    
    vector<pair<long long int,int>> p;
    for(int i=0;i<n;i++){
        p.push_back({x[i],i});
        p.push_back({y[i],i});
    }

    sort(p.begin(),p.end());
    vector<int> cnt(n,0);
    int pat=0;
    int tail=0;
    int head=0;
    while(true){
        if(pat==n){
            long long ret=(ma-mi)*(p[head-1].first-p[tail].first);
            res=min(ret,res);
            if(cnt[p[tail].second]==1) pat--;
            cnt[p[tail].second]--;
            tail++;
        }
        else{
            if(head==2*n) break;
            if(cnt[p[head].second]==0) pat++;
            cnt[p[head].second]++;
            head++;
        }
    }
    cout<<res<<endl;

    
    
    return 0;
}