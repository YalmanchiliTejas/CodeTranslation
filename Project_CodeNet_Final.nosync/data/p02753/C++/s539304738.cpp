#include <iostream>
#include <set>
#include <string>
using namespace std;
int main(){
    string s; cin >> s;
    set<char> st;
    for(int i=0;i<3;i++) st.insert(s[i]);
    if(st.size()==1) puts("No");
    else puts("Yes");
    return 0;
}