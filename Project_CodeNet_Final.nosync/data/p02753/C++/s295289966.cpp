#include<bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;
    bool flag=true;
    if(S[0]==S[1] && S[1]==S[2])
	flag=false;
    cout << (flag? "Yes": "No") << endl;
}
