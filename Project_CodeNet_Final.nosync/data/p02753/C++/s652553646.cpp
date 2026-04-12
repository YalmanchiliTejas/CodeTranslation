#define _LIBCPP_DEBUG 0
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll MOD = 1e9 + 7;
int INF=1<<30;


int main(void) {

    char a,b,c; cin>>a>>b>>c;
    set<char> st;
    st.insert(a);st.insert(b);st.insert(c);

    if(st.size()==1) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;

    return 0;
}