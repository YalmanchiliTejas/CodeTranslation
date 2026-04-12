#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
ios::sync_with_stdio(false);
std::cin.tie(nullptr);
string s;
set<char> a;
cin >> s;
for(ll i = 0; i < 3; i++){
    a.insert(s[i]);
}
cout << (a.size() == 1 ? "No" : "Yes") << endl;
}