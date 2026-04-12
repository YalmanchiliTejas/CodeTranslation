#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
    int H,W;
    cin >>H>>W;
    vector<string> a;
    for(int i=0; i<H; i++){
        string s;
        cin>>s;
        a.push_back(s);
    }

    for(int i=0; i<a.size(); i++){
       if(a[i].find("#") == string::npos){
           a.erase(a.begin()+i);
           i--;
       }
    }

    for(int i=0; i<a[0].size(); i++){
        bool ok = true;
        for(int j=0; j<a.size(); j++){
            if(a[j][i] == '#'){
                ok = false;
                break;
            }
        }
        if(ok){
            for(int j=0; j<a.size(); j++){
                a[j].erase(a[j].begin()+i);
            }
            i--;
        }
    }

    for(int i=0; i<a.size(); i++){
        cout << a[i] << endl;
    }
}