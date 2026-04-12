#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int n;
    cin >> n;
    map<char,int> m[n];
    string firststr;
    cin >> firststr;
    sort(firststr.begin(),firststr.end());
    for(char c : firststr){
        m[0][c]++;
    }
    firststr.erase(unique(firststr.begin(), firststr.end()), firststr.end());

    for(int i=1;i<n;i++){
        string str;
        cin >> str;
        for(char c : str){
            m[i][c]++;
        }
    }
    
    string res = "";
    for(int i=0;i<firststr.length();i++){
        int mi = INT_MAX;
        for(int j=0;j<n;j++){
            mi = min(mi,m[j][firststr.at(i)]);
        }
        res += string(mi,firststr.at(i));
    }

    cout << res;

    return 0;
}