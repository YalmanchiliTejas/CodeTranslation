#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string ss;
    cin >> n >> ss;
    ss+=ss[0];
    vector<int> s(n+1);
    for(int i = 0; i <= n; i++) {
        if(ss[i]=='o') s[i]=1;
        else s[i]=0;
    }
    vector<int> t(n+1,-1);
//    for(int i = 0; i < n; i++) {
//        cout << i+1 << "";
//    }
//    cout << "\n";
    for(int j = 0; j < 4; j++) {
        t[0]=j%2;
        t[1]=j/2;
        for(int i = 1; i < n; i++) {
            if(s[i]==t[i]) t[i+1]=t[i-1];
            else t[i+1]=1-t[i-1];
        }

        if(t[n]==t[0] && (((s[0]==t[0])&&(t[1]==t[n-1])) || ((s[0]!=t[0])&&(t[1]!=t[n-1])))){
            for(int i = 0; i < n; i++) {
                if(t[i]) cout << "S";
                else cout << "W";
            }
            cout << "\n";
            return 0;
        }
    }

    cout << "-1" << "\n";
    return 0;
}