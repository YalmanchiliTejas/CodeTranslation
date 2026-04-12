#include <bits/stdc++.h>
#define itn int
#define rep(i, n) for (int i = 0; i < n; i++)

using namespace std;
typedef long long ll;

int main(){
    int N;
    string s;
    int k;
    cin >> N >> s >> k;
    char tmp=s[k-1];
    rep(i, N){
        if(s[i]!=tmp){
            s[i]='*';
        }
    }
    cout << s << endl;
}
