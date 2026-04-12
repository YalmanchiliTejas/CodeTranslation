#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int cnt = 0, cnt2=0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'A') cnt++;
        else cnt2++;
    }
        
    if(cnt and cnt2)
        cout << "Yes";
    else    cout<<"No";


}