#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#define ll long long
#define endl '\n'
using namespace std;

int alpha[26];

int main(void)
{
    cin.tie(NULL); ios_base::sync_with_stdio(false); int N; cin >> N;
    string str; cin >> str;
    for(int i = 0; i < str.length(); i++)
        alpha[str[i] - 'a'] += 1;
    
    for(int i = 0; i < N - 1; i++)
    {
        cin >> str;
        auto temp = new int[26]();
        for(int j = 0; j < str.length(); j++)
            temp[str[j] - 'a'] += 1;
        for(int j = 0; j < 26; j++)
        {
            alpha[j] = min(alpha[j], temp[j]);
        }
        delete[] temp;
    }
    for(int i = 0; i < 26; i++)
    {
        while(alpha[i]--)
        {
            cout << (char)('a' + i);
        }
    }
    return 0;
}