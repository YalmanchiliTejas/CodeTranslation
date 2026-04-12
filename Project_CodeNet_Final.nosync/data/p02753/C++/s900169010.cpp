#include <iostream>
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    set<char>st;
    string p;
    cin >> p;
    for(int i = 0; i < 3; i++)
    {
        st.insert(p[i]);
    }
    if(st.size() == 2)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}
