#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using Graph = vector<vector<int>>;
using ll = long long;


int main() {
    string s;
    cin>>s;
    if(s[0]=='A'){
        if(s[1]=='A'&&s[2]=='A'){
            cout<<"No"<<endl;
            return 0;
        }
    }
    if(s[0]=='B'){
        if(s[1]=='B'&&s[2]=='B'){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
}