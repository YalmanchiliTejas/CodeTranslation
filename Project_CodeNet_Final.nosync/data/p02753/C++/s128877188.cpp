#include <bits/stdc++.h>
#define ll long long

using namespace std;
set < char > st;
int main()
{
    string s;  cin >> s;
    for(int i = 0;i<s.size();i++)  st.insert(s[i]);
    cout << (st.size() == 1 ? "No" : "Yes");
    return 0;
}
