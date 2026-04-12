#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main(){
    int n; cin >> n;
    string s; cin >>  s;
    int k; cin >> k;
    for(int i = 0; i < n; i++){
        if(s[i] != s[k-1]) cout << '*';
        else cout << s[i];
    }
    cout << endl;
    return 0;
}