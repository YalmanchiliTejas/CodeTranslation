#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); // cin, cout の高速化
#define MOD 1000000007
#define REP(i, n) for (int i = 0; i < (n); i++)
#define REP1(i, n) for (int i = 1; i <= (n); i++)

#define MAX_N 10000000

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> M;
    REP(i, h)
    {
        string s;
        cin >> s;
        bool flg = false;
        REP(j, s.length())
        {
            if (s[j] == '#')
            {
                flg = true;
                break;
            }
        }
        if (flg)
        {
            M.push_back(s);
        }
    }
    REP(ii, w)
    {
        int i = w-1-ii;
        bool flg = false;
        REP(j, M.size())
        {
            if(M[j][i] == '#'){
                flg = true;
                break;
            }
        }
        if (!flg){
            REP(j, M.size())
            {
                M[j] = M[j].erase(i,1);
            }
        }
    }
    REP(i,M.size()){
        cout<<M[i]<<endl;
    }
}