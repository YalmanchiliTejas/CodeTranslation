#include <bits/stdc++.h>
using namespace std;
string n;
int main (){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin >> n;
if (n[0]==n[1] and n[1]==n[2]) cout << "No";
else cout << "Yes";
return 0;
}
