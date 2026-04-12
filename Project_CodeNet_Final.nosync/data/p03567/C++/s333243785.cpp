
#include<iostream>
#include<math.h>
#include<cstring>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<queue>
#include<string>
#include<ctime>
//#include "optimization.h"
#include<bitset>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
typedef long long ll;
using namespace std;
const int N =  3e5 +100;
ll INF = (1LL << 62) - 1;
ll MOD = 1e9 + 7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    s += '#';
    for(int i= 0; i < s.size()-  1; i++)
    {
        if(s[i] == 'A' && s[i+1] == 'C' )
        {
         cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}