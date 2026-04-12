#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    string r,g,b;
    cin>>r>>g>>b;
    string s=r+g+b;
    int k=stoi(s);
    if (k%4==0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
