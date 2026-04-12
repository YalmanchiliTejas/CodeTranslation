#include <bits/stdc++.h>
using namespace std;

bool f(string s){
    for(int i=0; i<s.size(); ++i){
        if(s[i]!='.'){return false;}
    }
    return true;
}

bool g(const vector<string> &s, int j){
    for(int i=0; i<s.size(); ++i){
        if(s[i][j]!='.'){return false;}
    }
    return true;
}

int main(){
    int h, w; cin >> h >> w;
    vector<string> s(h);
    vector<int> vi(h, 0), vj(w, 0);
    for(int i=0; i<h; ++i){cin >> s[i];}
    for(int i=0; i<h; ++i){
        string t = s[i]; //cout << t << "," << f(t) << endl;
        if(f(t)){vi[i]++;}
    }
    for(int i=0; i<w; ++i){
        if(g(s, i)){vj[i]++;}
    }
    for(int i=0; i<h; ++i){
      	if(vi[i]!=0){continue;}
        for(int j=0; j<w; ++j){
        	if(vj[j]!=0){continue;}
            cout << s[i][j];
        }
        cout << endl;
    }
    return 0;
}