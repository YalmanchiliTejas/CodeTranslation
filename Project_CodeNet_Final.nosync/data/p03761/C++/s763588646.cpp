#include <bits/stdc++.h>
using namespace std;

int64_t MOD = 1000000007;
int64_t MAX = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    int N;
    map<char, int> list;
    for (auto x = 'a'; x <= 'z'; x++)
        list[x] = MOD;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string tmp;
        cin >> tmp;
        map<char, int> temp;
        for (auto x = 'a'; x <= 'z'; x++)
            temp[x] = 0;
        for (int j = 0; j < tmp.size(); j++)
            temp[tmp[j]]++;
        for (auto x : temp)
            list[x.first] = min(x.second, list[x.first]);
    }
    string ans = "";
    for (auto x : list)
        for (int i = 0; i < x.second; i++)
            ans.push_back(x.first);
    cout << ans;
}