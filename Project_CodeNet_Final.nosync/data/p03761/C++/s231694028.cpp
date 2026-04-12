#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 51;
int alphabet[MAX_N][26];
int N;

void init() {
    cin >> N;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < 26; ++j) alphabet[i][j] = 0;
        string S;
        cin >> S;
        for(int j = 0; j < S.size(); ++j) ++alphabet[i][S[j] - 'a'];
    }
}

int main()
{
    init();
    int res[26];
    fill(res, res + 26, 100);
    for(int i = 0; i < N; ++i) 
        for(int j = 0; j < 26; ++j)
            res[j] = min(res[j], alphabet[i][j]);
    
    string T;
    for(int i = 0; i < 26; ++i)
        for(int j = 0; j < res[i]; ++j)
            T.push_back('a' + i);
    
    cout << T << endl;
    return 0;
}