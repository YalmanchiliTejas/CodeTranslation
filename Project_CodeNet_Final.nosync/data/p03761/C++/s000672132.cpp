#include <bits/stdc++.h>
using namespace std;

char abcde[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

int main(){
    int n;
    cin >> n;
    string s;
    vector<vector<int>> abc(26, vector<int>(n) );

    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < s.size(); j++)
        {
            ++abc.at(s.at(j) - 'a').at(i);
        }
    }

    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < *min_element(abc.at(i).begin(), abc.at(i).end() ); j++)
        {
            printf("%c", abcde[i]);
        }
    }
    cout << endl;
    return 0;
}