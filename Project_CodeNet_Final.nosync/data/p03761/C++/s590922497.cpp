/**
*    author:  souzai32
*    created: 01.08.2020 17:22:10
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n){
        cin >> s.at(i);
        sort(s.at(i).begin(),s.at(i).end());
    }

    vector<int> alp(26);
    vector<int> ans(26,100);
    int count=0;

    rep(i,n){
        int k=0;
        rep(j,s.at(i).size()){
            alp.at(s.at(i).at(j)-'a')++;
        }
        rep(j,26){
            ans.at(j)=min(ans.at(j),alp.at(j));
            alp.at(j)=0;
        }
    }

    char a='a';
    rep(i,26){
        //cout << ans.at(i) << endl;
        rep(j,ans.at(i)) cout << a;
        a++;
    }
    cout << endl;

    return 0;
}