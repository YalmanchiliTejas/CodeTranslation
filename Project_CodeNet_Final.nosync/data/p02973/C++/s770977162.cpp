#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=1e9;

int main(){
    int n;
    cin>>n;
    int a;
    multiset<int> ms;
    for(int i=0;i<n;i++){
        cin>>a;
        auto it=ms.lower_bound(a);
        if(it!=ms.begin()){
            ms.erase(prev(it));
        }
        ms.insert(a);
    }
    cout<<ms.size()<<endl;
}
