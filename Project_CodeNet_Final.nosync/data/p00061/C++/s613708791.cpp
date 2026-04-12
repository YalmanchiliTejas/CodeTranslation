#include<bits/stdc++.h>
using namespace std;



struct team{
    int num;
    int score;
};

bool comp(team a, team b){
    return a.score < b.score;
}

int main(){

    vector<team> t;
    int n;
    while(1){
        string s; cin >> s;
        if(s == "0,0") break;
        s += ",";
        int a, b;
        string A;
        int idx = 0;
        for(;;idx++){
            if(s[idx] == ',') break;
            else A += s[idx];
        }
        a = stoi(A);
        idx++;
        string B;
        for(;;idx++){
            if(s[idx] == ',') break;
            else B += s[idx];
        }
        b = stoi(B);
        
        team tmp;
        tmp.num = a;
        n = a;
        tmp.score = b;
        t.push_back(tmp);
    }

    vector<team> _t(n);
    for(int i = 0; i < n; i++) _t[i] = t[i];

    sort(t.begin(), t.end(), comp);
    map<int, int> m;

    int j = 2;
    m[t[n - 1].score] = 1;
    for(int i = n - 2; i >= 0; i--){
        if(t[i].score != t[i + 1].score){
            m[t[i].score] = j;
            j++;
        }
    }
    //cout << t[0].score << " " << t[n - 1].score << endl;

    int q;
    while(cin >> q){
        int sc = _t[q - 1].score;
        cout << m[sc] << endl;
    }
    return 0;
}
