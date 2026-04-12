#include <bits/stdc++.h>
using namespace std;
int N;
using ll = long long;


int main(){
    cin >> N;
    vector<vector<int>> S(26, vector<int>(N, 0));
    string buf;
    for(int i = 0; i< N; i++){
        cin >> buf;
        for(char s : buf){
            S.at(s -'a').at(i)++;
        }
    }

    for(int i = 0; i<26; i++){
        sort(S.at(i).begin(), S.at(i).end());
        if(S.at(i).at(0)!= 0){
            cout << string(S.at(i).at(0), 'a' + i);
        }
    }
    cout << endl;
    // for (vector<int> ve : S)
    // {
    //     for (int aaa : ve)
    //     {
    //         cout << aaa;
    //     }
    //     cout << endl;
    // }
}