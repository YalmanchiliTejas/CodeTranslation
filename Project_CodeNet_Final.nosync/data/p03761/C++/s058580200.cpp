#include<iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;
using ll=long long;
double mod = 1e9 + 7;
#define REP(i, n)  for(int i = 0; i < (int)n; ++i)
#define REP1(i, n)  for(int i = 1; i < (int)n; ++i)
#define REPll1(i, n)  for(ll i = 1; i*i < (int)n; ++i)

int cnt(ll n) {
    int c = 0;
    while (true) {
        if (n < 1)break;
        n = n / 10;
        c++;
    }
    return c;
}


int main() {
    ll N = 0, M = 0, al_num = 1000, tmp = 0;
    string answer = "";
    char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                         's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int num = 26;
    int al[26];
    string s, S[60];
    cin >> N;
    REP(i, N)cin >> S[i];
    REP(i, num) {
        REP(j, N) {
            tmp = count(S[j].cbegin(), S[j].cend(), alphabet[i]);
            if (al_num > tmp)al_num = tmp;
        }
        al[i] = al_num;
        al_num = 1000;
    }
    REP(i, num) {
        int n = al[i];
        REP(j, n) {
            answer += alphabet[i];
        }
    }
    cout << answer << endl;
}