#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    string str;
    cin >> str;
    int ok = 0;
    for(int i = 0; i < str.size()-1; i++){
        if(str[i] == 'A' && str[i+1] == 'C') ok = 1;
    }
    if(ok == 1) cout << "Yes" << endl;
    if(ok == 0) cout << "No" << endl;
}
