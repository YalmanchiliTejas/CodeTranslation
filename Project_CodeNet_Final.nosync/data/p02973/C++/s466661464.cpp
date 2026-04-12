#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;scanf("%d",&n);
    vector<int> a(n),p(n,1e9+7);
    for(int i=0;i<n;i++)scanf("%d",&a[n-1-i]);
    for(int i=0;i<n;i++){
        *upper_bound(p.begin(),p.end(),a[i])=a[i];
    }
    int ans=lower_bound(p.begin(),p.end(),1e9+7)-p.begin();
    printf("%d\n",ans);
    return 0;
}