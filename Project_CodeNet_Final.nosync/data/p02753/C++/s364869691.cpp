#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define pb push_back
#define all(v) v.begin(), v.end()
#define bigger (char)toupper
#define smaller (char)tolower
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;

int main() {
    string s; cin>>s;
    if(s[0]==s[1]&&s[1]==s[2]) {
        cout<<"No"<<endl;
    }
    else cout<<"Yes"<<endl;
}