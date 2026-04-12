#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
int main()
{
    int N, M;
    cin >> N >> M;

    string ans = "Yes";
    if(N!=M) ans = "No"; 
    cout << ans << endl;

   return 0;
}