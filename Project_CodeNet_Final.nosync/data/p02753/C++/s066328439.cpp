#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define n1		      "\n"
#define B                     begin()
#define E                     end()
#define F                     first
#define S                     second
#define pb                    push_back
#define pf                    push_front
#define popb                  pop_back()
#define popf                  pop_front()

const int BIG=1e5+55;
const int BIGG=1e9+7;
const ll BIGGE=1e12+55;
const double SML=(1e-7);

using namespace std;

    string s;
    bool g1,g2;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cout.tie(NULL);
    cin >>s;
    for (int i=0; i<s.size(); i++)
        if (s[i] == 'A')
            g1 = 1;
        else
            g2 = 1;
    if (g1 && g2)
        cout <<"Yes";
    else
        cout <<"No";


    return 0;
}
