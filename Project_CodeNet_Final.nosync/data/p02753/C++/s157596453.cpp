#include <bits/stdc++.h>
using namespace std;

int main(){
    int total=0;
    string companies;
    cin >> companies;
    for(int i=0; i<3; i++){
        if(companies[i]=='A')total++;
    }
    if(total == 3 || total == 0) cout << "No\n";
    else cout << "Yes\n";
    return 0;
}