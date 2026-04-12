#include <bits/stdc++.h>
using namespace std;

using lli = long long int;

template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}

template <class T>ostream &operator<<(ostream &o,const pair<T, T>&p)
{o<<"("<<p.first<<", "<<p.second<<")";return o;}

#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main(void){
    string s;
    cin >> s;
    if(s[0] == s[1] && s[1] == s[2]) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}
