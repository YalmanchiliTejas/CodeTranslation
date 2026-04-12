#include <bits/stdc++.h>
using namespace std;
#define REP(i, s, n) for (int i = s; i < n; ++i)
#define rep(i, n) REP(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())
#define IINF INT_MAX
#define LLINF LLONG_MAX
#define DEBUG true
// sort(a.begin(), a.end(), std::greater<int>());

/*
std::vector<std::string> split(const std::string &input, char delimiter)
{
    std::istringstream stream(input);

    std::string field;
    std::vector<std::string> result;
    while (std::getline(stream, field, delimiter))
    {
        result.push_back(field);
    }
    return result;
}
*/

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    cout<<(a-c)/(b+c)<<endl;
    return 0;
}