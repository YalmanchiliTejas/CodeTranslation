#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main(void){
    int n; cin >> n;
    vector<vector<ll>>cnt('z'+10,vector<ll>(n,0));
    for(int i=0;i<n;i++){
        string s; cin >> s;
        for(int j=0;j<s.length();j++){
            cnt[s[j]][i]++;
        }
    }

    // for(int i='a';i<='z';i++){
    //     for(int j=0;j<n;j++){
    //         cout << cnt[i][j] << ' ';
    //     }cout << endl;
    // }

    for(int i='a';i<='z';i++){
        ll num = *min_element(cnt[i].begin(),cnt[i].end());
        string t(num,char(i));
        cout << t;
    }
    cout << endl;
    return 0;
}