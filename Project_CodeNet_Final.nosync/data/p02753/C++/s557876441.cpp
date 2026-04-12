#include <bits/stdc++.h>
using namespace std;

string s;

int main()
{
    cin>>s;
    if (s.at(0)==s.at(1)&&s.at(1)==s.at(2)) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;

    return 0;
}
