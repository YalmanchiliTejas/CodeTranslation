#include <bits/stdc++.h>
using namespace std;
 
string S; int N, cnt;
 
int main() {
	string S;
    cin >> S;
    if(S[0]==S[1]){
        if(S[1]==S[2])cout << "No" << endl;
        else cout << "Yes" << endl;
    }else cout << "Yes" << endl;
}