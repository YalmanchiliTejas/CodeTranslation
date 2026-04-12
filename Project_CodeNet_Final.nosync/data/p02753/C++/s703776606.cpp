#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	string S;
	cin >> S;
    int bus=0;
    if(S.at(0) != S.at(1) || S.at(1) != S.at(2)){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
	return 0;
}
