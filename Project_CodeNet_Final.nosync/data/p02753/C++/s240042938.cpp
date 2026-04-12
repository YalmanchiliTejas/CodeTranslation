#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    string s; cin >> s;
    set<char>st;
    for(auto c : s){
        st.insert(c);
    }
    if(st.size() == 2) cout << "Yes" << endl;
    else cout << "No" << endl;
	return 0;
}
