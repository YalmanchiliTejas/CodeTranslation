#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstring>
#include<map>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define REP(n) rep(i,n)
#define all(n) n.begin(),n.end()

const int MAXP = 31;

int main()
{
    string s;
    int n, w, l, e;
    bool sec = false;
    while(cin >> n && n)
    {
        if(sec) cout << endl;
        vector<string> teams[MAXP];
        
        REP(n)
        {
            cin >> s >> w >> l >> e;
            teams[w * 3 + e].push_back(s);
        }
        
        for(int i = MAXP-1;i!= -1; i--)rep(j,teams[i].size())
            cout << teams[i][j] << "," << i << endl;
        
        sec = true;

    }

    return 0;
}