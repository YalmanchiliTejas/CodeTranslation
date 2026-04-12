#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<queue<char>> s(n);
    for(int i = 0; i < n; i++){
        string a;
        cin >> a;
        for(char b : a){
            s.at(i).push(b);
        }
    }

    for(int i = 1; i < n; i++){
        int t = s.at(0).size();
        for(int j = 0; j < t; j++){
            char tmp = s.at(0).front();
            s.at(0).pop();
            int u = s.at(i).size();
            for(int k = 0; k < u; k++){
                char tar = s.at(i).front();
                s.at(i).pop();
                if(tmp == tar){
                    s.at(0).push(tmp);
                    break;
                }
                s.at(i).push(tar);
            }
        }
    }
    vector<char> ans;
    while(s.at(0).size() > 0){
         ans.push_back(s.at(0).front());
        s.at(0).pop();
    }
    sort(ans.begin(), ans.end());
    for(char c : ans){
        cout << c;
    }
    cout << endl;
}