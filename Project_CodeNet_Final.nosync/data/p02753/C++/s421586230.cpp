#include<bits/stdc++.h>
using namespace std;
int main()
{


string s; cin >> s; int l=s.size();
sort(s.begin(),s.end());
    if(s[0]=='A' && s[l-1]=='B')
     cout <<"Yes"<<endl;
    else cout << "No";
    return 0;
}
