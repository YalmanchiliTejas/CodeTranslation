#include <bits/stdc++.h>
using namespace std;

#define FasterIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(v) v.begin(), v.end()
const int MOD = 1e9+7;

int main(){
    FasterIO;

    int n, k;
    string s;

    while(cin>>n>>s>>k){
        for(int i=0; i<n; i++){
            if(s[i]!=s[k-1])
                s[i] = '*';
        }

        cout<<s<<endl;
    }

    return 0;
}

