#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;scanf("%d",&n);
    vector<int> a;
    for(int i=0;i<n;i++){
        int p;scanf("%d",&p);
        auto itr=lower_bound(a.begin(),a.end(),p);
        if(itr==a.begin())a.emplace(a.begin(),p);
        else itr--,*itr=p;
    }
    printf("%d\n",a.size());
    return 0;
}