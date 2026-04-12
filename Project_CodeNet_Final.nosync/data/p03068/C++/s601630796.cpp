#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll;
int main(){
    int n,k;
    string s;
    cin >> n >> s >> k;
    rep(i,n){
        if(s[i] != s[k-1]){
            cout << '*';
        }
        else{
            cout << s[i];
        }
    }
    cout << endl;
}