#include<bits/stdc++.h>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < n;i++)
 
int main(){
 
    string S;
    cin >> S;
    if(S.at(0)=='A'&&S.at(1)=='A'&&S.at(2)=='A'||S.at(0)=='B'&&S.at(1)=='B'&&S.at(2)=='B')
        cout << "No" << endl;
    else
        cout << "Yes" << endl;

            return 0;
}