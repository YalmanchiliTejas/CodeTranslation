#include<bits/stdc++.h>
using namespace std;
#define Yes(n) cout << ((n) ? "YES" : "NO") << endl
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(V) (V).begin(),(V).end()
#define SORT(V) sort(ALL(V))

vector<string> split(string,string);

int main()
{
    int i;
    cin >> i;
    if(i == 3 || i == 5 || i == 7)
    {
        Yes(true);
    }else
    {
        Yes(false);
    }
    
}

vector<string> split(string str, string separator) 
{
    if (separator == "") 
        return {str};
    vector<string> result;
    string tstr = str + separator;
    long long unsigned int l = tstr.length(), sl = separator.length();
    string::size_type pos = 0, prev = 0;
    
    for (;pos < l && (pos = tstr.find(separator, pos)) != string::npos; prev = (pos += sl))
    {
        result.emplace_back(tstr, prev, pos - prev);
    }
    return result;
}