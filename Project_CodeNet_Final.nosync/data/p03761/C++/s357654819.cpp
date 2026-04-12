#include <bits/stdc++.h>
using namespace std;
#define REP(i, t) for(int i = 0; i < t; i++)

int main()
{
    int n;
    string S[55];
    cin >> n;
    REP(i, n) cin >> S[i];

    int li_let[26];
    fill(&li_let[0], &li_let[26], 100);
    int count_let;
    char tar;
    REP(i, n)       //i文字目を判定
    {
        REP(j, 26)  //アルファベットj文字目
        {
            if (li_let[j] == -1) continue;
            tar = 'a' + j;
            count_let = count_if(S[i].begin(), S[i].end(), [tar](char let) { return let == tar; });
            0 < count_let ? li_let[j] = min(count_let, li_let[j]) : li_let[j] = -1;
        }
    }

    REP(i, 26) if(0 < li_let) REP(j, li_let[i]) cout << char('a' + i);
    cout << endl;

    return 0;
}
