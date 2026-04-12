#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
    string c;
    cin>>c;
    vector<string> vv(5);
    vv[0]="a";
    vv[1]="e";
    vv[2]="i";
    vv[3]="o";
    vv[4]="u";
    bool ans=false;
    for (int i=0; i<5; i++){
        if (c==vv[i]) ans=true;
    }
    if (ans) cout<<"vowel"<<endl;
    else cout<<"consonant"<<endl;
}
