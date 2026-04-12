#include <bits/stdc++.h>
#include <algorithm>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(x) (x).begin(), (x).end()
#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long ll;
 
int main() {

    string s;
    cin >> s;

    int ans=false;
    rep(i,2) {
        if(s[i]!=s[i+1]) ans=true;
    }

    if(ans)    cout<<"Yes"<<endl;
    else    cout<<"No"<<endl;


 return 0;
}