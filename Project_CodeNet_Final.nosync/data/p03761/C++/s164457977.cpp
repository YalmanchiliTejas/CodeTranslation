#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<stdio.h>
#include<queue>
const int mod = 1e9 + 7;
const int INF = 1e9;
using namespace std;
typedef long long ll;


int main()
{
    int n;
    cin >> n;
    int a[26];
    int b[26];
    for(int i = 0; i < 26; i++){
        a[i] = INF;
        b[i] = 0;
    }
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int i = 0; i < s.size(); i++){
            b[s[i] - 'a']++;
        }
        for(int i = 0; i < 26; i++){
            a[i] = min(a[i],b[i]);
        }
        for(int i = 0; i < 26; i++){
            b[i] = 0;
        }
    }
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < a[i]; j++){
            cout << static_cast<char>('a' + i);
        }
    }
    cout << endl;
}