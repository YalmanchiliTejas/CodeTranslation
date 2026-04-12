#include <bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,a,b) for(int i=a;i<b;i++)
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define itrep(it,v) for(auto it=(v).begin();it!=(v).end();it++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define vi vector<int>
#define pb push_back
#define pi pair<int,int>
#define vp vector<pair<int,int> >
#define mp make_pair
#define all(v) (v).begin(),(v).end()
using namespace std;

            
signed main(){
    string s;
    int a;
    cin>>s>>a;
    int b=s[0]-'0';
    for(int i=1;i<s.length();i+=2){
        if(s[i]=='+')b=b+(s[i+1]-'0');
        else b=b*(s[i+1]-'0');
    }
    stack<int> st;
    st.push(s[0]-'0');
    for(int i=1;i<s.length();i+=2){
        if(s[i]=='+')st.push(s[i+1]-'0');
        else{
            int t=st.top();
            st.pop();
            st.push(t*(s[i+1]-'0'));
        }
    }
    int c=0;
    while(!st.empty()){
        c+=st.top();
        st.pop();
    }
    if(b==a&&c==a)cout<<"U"<<endl;
    else if(b==a)cout<<"L"<<endl;
    else if(c==a)cout<<"M"<<endl;
    else cout<<"I"<<endl;
    return 0;
}
