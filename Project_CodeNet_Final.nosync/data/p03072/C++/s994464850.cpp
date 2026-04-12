#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <map>
using namespace std;
#define REP(i, a, n) for (int i = ((int)a); i < ((int)n); i++)
#define lli long long int

#define MAX 100000000
//#define DEBUG

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main()
{
#ifdef DEBUG
    cout << "DEBUG MODE" << endl;
#else
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
#endif
    int n;
    cin>>n;
    int max=0;
    int ans=0;
    int h;
    for(int i = 0; i < n; i++)
    {
        cin>>h;
        if(h>=max){
            max=h;
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
/* 注意すべき点
グローバル以外の配列は初期化すべし
*/