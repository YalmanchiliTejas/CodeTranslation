#include <bits/stdc++.h>
using namespace std;
#define ll long long

typedef pair<int,int> P;

int main(){
    string s;
    cin >> s;
    bool a = false,b = false;
    for (int i = 0; i < s.size(); i++){
        if (s.at(i) == 'A') a = true;
        if (s.at(i) == 'B') b = true;
    }
    if (a && b){
        cout << "Yes" << "\n";
    }else{
        cout << "No" << "\n";
    }
}