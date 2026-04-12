#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    set<int> st;

    for(auto num:a){
        int t=num;
        for(int i=2;i*i<=num;++i){
            while(t%i==0){
                t/=i;
                st.insert(i);
            }
        }
        if(num!=1)st.insert(num);
    }
    long long ans=0;
    for(auto div:st){
        long long tans=0;
        for(int i=0;i<n;++i){
            if(a[i]%div==0)tans+=a[i];
        }
        ans=max(ans,tans);
    }
    cout<<ans<<endl;

    return 0;
}
