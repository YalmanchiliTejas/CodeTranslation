#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios_base:: sync_with_stdio(false);
    string s;cin>>s;
    set<char> st;
    for(auto &ele:s)st.insert(ele);
    cout<<(st.size()==2?"Yes":"No");
}




