#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long int i=0;i<n;++i)
typedef long long int ll;

int main(){

    int n;
    cin >> n;
    vector<string> s(n);

    rep(i,n){
        cin >> s[i];
    }

    vector<int> a(26,60);

    for(int i=0;i<n;i++){
        vector<int> b(26,0);
        rep(j,s[i].size()){
            b[s[i][j]-'a']++;
        }
        rep(j,26){
            a[j]=min(a[j],b[j]);
        }
    }

    string AL="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string al="abcdefghijklmnopqrstuvwxyz";

    for(int i=0;i<26;i++){
        for(int j=0;j<a[i];j++){
            cout << al[i];
        }
    }

    cout << endl;

    return 0;
}