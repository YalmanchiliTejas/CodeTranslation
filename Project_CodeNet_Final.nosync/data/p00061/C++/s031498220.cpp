#include <bits/stdc++.h>
using namespace std;

int main(void){
    int a,b;
    char c;
    vector<pair<int,int> >st;
    while(true){
        cin>>a>>c>>b;
        if(a==0&&b==0)break;
        st.push_back(make_pair(b,a));
    }
    sort(st.begin(),st.end(),greater<pair<int,int> >());
    int n;
    int t;
    int ans;
    while(true){
        cin>>n;
        if(cin.fail())break;
        t=st[0].first;
        ans=1;
        for (int i = 0; i < st.size(); ++i) {
            if(st[i].first!=t){t=st[i].first,ans++;}
            if(st[i].second==n){cout<<ans<<endl;break;}
        }
    }
    return 0;
}
