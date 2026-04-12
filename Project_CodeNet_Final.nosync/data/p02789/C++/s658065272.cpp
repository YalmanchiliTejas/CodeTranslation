#include <bits/stdc++.h>
using namespace std;

using lli = long long int;

template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}

template <class T>ostream &operator<<(ostream &o,const pair<T, T>&p)
{o<<"("<<p.first<<", "<<p.second<<")";return o;}

int main(void){
    int n, m;
    cin >> n >> m;
    if(n == m) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
