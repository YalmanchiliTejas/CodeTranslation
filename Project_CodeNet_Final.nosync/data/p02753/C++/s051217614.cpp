#include <bits/stdc++.h>
using namespace std;

const string YES = "Yes";
const string NO = "No";

void solve(std::string S)
{
    map<char,int> mp;
    for(unsigned int i=0;i<S.size();i++)
    {
        mp[S[i]]++;
    }
    if(mp['A']&&mp['B'])
        cout<<YES<<endl;
    else
        cout<<NO<<endl;
}

int main()
{
    std::string S;
    std::cin >> S;
    solve(S);
    return 0;
}
