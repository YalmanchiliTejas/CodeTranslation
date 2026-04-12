#include<bits/stdc++.h>
using namespace std;
int a[200009],ans[200009];
main(){
    vector<pair<int,int> > v;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >>a[i];
        v.push_back({a[i],i});
    }
    sort(v.begin(),v.end());
    for(int i =0 ; i < n/2; i++)
        ans[v[i].second]=v[n/2].first;
    for(int i =n/2 ; i < n; i++)
        ans[v[i].second]=v[n/2-1].first;
    for (int i= 0 ;i < n; i++)
        cout<<ans[i]<<endl;

}
