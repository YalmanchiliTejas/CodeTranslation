#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=1e5+7;
multiset <int> ms;
int a[maxn];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        auto it=ms.lower_bound(a[i]);
        if(it!=ms.begin()){
            it--;
            ms.erase(it);
        }
        ms.insert(a[i]);
    }
    cout<<ms.size()<<endl;
    return 0;
}
