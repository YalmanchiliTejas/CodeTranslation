#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[100005];
vector<int> v;
int main(){
    ios::sync_with_stdio(false);
    cin>>n;for(int i=n;i>=1;i--)cin>>a[i];
    v.push_back(a[1]);
    for(int i=2;i<=n;i++){
        int id = upper_bound(v.begin(),v.end(),a[i])-v.begin();
        if(id==v.size())v.push_back(a[i]);
        else v[id]=a[i];
    }
    cout<<v.size();
}