#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ft first
#define sd second
#define fr(i,n) for(int i=0;i<(n);++i)
#define Fr(i,n) for(int i=1;i<=(n);++i)
#define ifr(i,n) for(int i=(n)-1;i>=0;--i)
#define iFr(i,n) for(int i=(n);i>0;--i)

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int> a(n);
    fr(i,n) cin>>a[i];
    multiset<int> st;
    fr(i,n){
        auto it=st.lower_bound(a[i]);
        if(it==st.begin()) st.insert(a[i]);
        else{
            int m=*(--it);
            st.erase(it);
            st.insert(a[i]);
        }
    }
    cout<<st.size()<<endl;
}