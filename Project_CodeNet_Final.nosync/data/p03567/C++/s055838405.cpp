#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;
    int len = s.size();
    for(int i=0;i<len-1;i++){
        if(s[i]=='A'&&s[i+1]=='C'){cout << "Yes" << endl;
        return 0;}
    }
    cout << "No" << endl;
    return 0;
}