#include<bits/stdc++.h>
using namespace std;

#define PI 3.1415926535897932


int main(){
    int mod=1000000007;
    int n;
    scanf("%d",&n);
    vector <int> a(n);
    for (auto&e:a) scanf("%d",&e);
    vector <int>d;
    for (int i=0;i<n;i++) {
        auto it=lower_bound(d.rbegin(),d.rend(),a[i]);
        if (it==d.rbegin()) {
            d.push_back(a[i]);
        } else {
            --it;
            *it=a[i];
        }
    }
    int ans=d.size();
    printf("%d\n",ans);
    return 0;
}