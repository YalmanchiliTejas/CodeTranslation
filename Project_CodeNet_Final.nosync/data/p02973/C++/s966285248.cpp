#include <bits/stdc++.h>
using namespace std;

const int maxn=2e5+5;
int a[maxn];
bool vis[maxn];

int main()
{
    int n;
    while(cin>>n){
        memset(vis, 0, sizeof(vis));
        multiset<int> LIS;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        LIS.emplace(a[0]);
        for(int i=1;i<n;i++){
            if(a[i]<=*LIS.begin()){
                LIS.emplace(a[i]);
            }
            else{
                auto it = LIS.lower_bound(a[i]);
                if(it!=LIS.begin()) it--;
                LIS.erase(it);
                LIS.emplace(a[i]);
            }
        }
        cout<<LIS.size()<<endl;
    }
    return 0;
}
