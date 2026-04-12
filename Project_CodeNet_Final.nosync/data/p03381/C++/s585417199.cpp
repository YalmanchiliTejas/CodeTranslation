#include<bits/stdc++.h>
using namespace std;
int n,i,d;
vector<pair<int,int>> v,ans;
int main(){
    scanf(" %d",&n);
    for(i=0;i<n;i++){
        scanf(" %d",&d);
        v.push_back({d,i});
    }
    sort(v.begin(),v.end());
    int mid=n/2;
    for(i=0;i<n;i++){
        if(i<mid)     ans.push_back({v[i].second,v[mid].first});
        if(i>=mid)    ans.push_back({v[i].second,v[mid-1].first});
    }
    //cout << v[mid].first << ' ' << v[mid-1].first << endl;
    sort(ans.begin(),ans.end());
    for(i=0;i<n;i++){
        printf("%d\n",ans[i].second);
    }
}
