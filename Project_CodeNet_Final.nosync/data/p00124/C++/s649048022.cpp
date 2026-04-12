#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define REP(n) rep(i,n)
#define all(n) n.begin(),n.end()

typedef pair<int, int> pp;
typedef pair<pp, string> ppp;

int main()
{
    int sec = 0, n;
    while(cin >> n && n)
    {
        if(sec) cout << endl;
        vector<ppp> res;
        string t;
        int win, lose, even;
        REP(n)
        {
            cin >> t >> win >> lose >> even;
            res.push_back(ppp(pp(-(win * 3 + even * 1), i), t));
        }
        sort(all(res));
        REP(n) cout <<  res[i].second << "," <<-res[i].first.first << endl;
        sec = 1;
    }

    return 0;
}