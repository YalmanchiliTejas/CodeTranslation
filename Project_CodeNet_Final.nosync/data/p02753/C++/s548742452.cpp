#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
const int INF = 1e9;
const int MOD = 1000000007;


int main() {
        string s;
        cin >> s;
        set<char> st;
        rep(i,3){
                 st.insert(s.at(i));
        }
        if(st.size() == 2) cout <<"Yes" << endl;
        else cout <<"No"<< endl;
                 
        
        return 0;
}


