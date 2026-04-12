#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;


    if((count(s.begin(), s.end(), 'A') >2) ||  (count(s.begin(), s.end(), 'B') >2))
        cout<<"No";
    else
        cout<<"Yes";


}
