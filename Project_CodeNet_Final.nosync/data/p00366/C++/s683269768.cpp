#include<bits/stdc++.h>
using namespace std;

int n;

vector<int> v;
vector<int> vv;


int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        v.push_back(t);
    }
    sort(v.begin(),v.end());
    int mx=v.back();
    for(int i=1;i<=mx;i++){
        if((mx%i)==0){
            vv.push_back(i);
        }
    }
    sort(vv.begin(),vv.end());
    long long int ans=0;
    for(int i=0;i<v.size();i++){
        int id=lower_bound(vv.begin(),vv.end(),v[i])-vv.begin();
        ans+=vv[id]-v[i];
    }
    printf("%lld\n",ans);
    return 0;
}
