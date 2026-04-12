#include<bits/stdc++.h>
using namespace std;

int main(){

    int n; cin >> n;
    vector<vector<int> > a(n, vector<int> (30, 0));
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        for(int j = 0; j < s.size(); j++){
            a[i][(int)(s[j] - 'a')]++;
        }
    }

    vector<char> ans;

    for(int i = 0; i < 26; i++){
        int num = 1000;
        for(int j = 0; j < n; j++){
            num = min(num, a[j][i]);
        }

        //cout << num << endl;
        for(int j = 0; j < num; j++) ans.push_back(i + (int)'a');
    }

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i];
    }
    cout << endl;
    return 0;
}