#include <bits/stdc++.h>
#include<math.h>
#include<queue>
#include<cstdio>
#include<set>
#include<map>
using namespace std;

int main(){
    string S;
    cin >> S;
    if(S.at(0)==S.at(1) && S.at(1)==S.at(2)) cout << "No";
    else cout << "Yes" << endl;
    return 0;
}