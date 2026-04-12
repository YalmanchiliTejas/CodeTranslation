#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second
typedef pair<ll,ll> P;
using VP = vector<P>; using VVP = vector<VP>;
using VI = vector<ll>; using VVI = vector<VI>; using VVVI = vector<VVI>;
const int inf=1e9+7;
const ll INF=1LL<<61;
const ll mod=1e9+7;

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

int main(){
    int i,j;
    int n;
    while(1){
        cin>>n;
        if(n==0) break;
        stack<P> st;
        int w=0;
        for(i=1;i<=n;i++){
            int x;
            cin>>x;
            if(i%2==1){
                if(i==1) st.push(P(x,1));
                else{
                    P u=st.top();
                    if(u.fi==x) st.top().se++;
                    else st.push(P(x,1));
                }
            }
            else {
                P u=st.top();
                if(u.fi==x) st.top().se++;
                else {
                    st.pop();
                    int r=1+u.se;
                    if(st.size()) {
                        r+=st.top().se;
                        st.pop();
                    }
                    st.push(P(x,r));
                }
            }
        }
        ll sum=0;
        while(st.size()){
            sum+=(1-st.top().fi)*st.top().se;
            st.pop();
        }
        cout<<sum<<endl;
    }
}
