#include <bits/stdc++.h>
using namespace std;

using lli = long long int;

template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}

template <class T>ostream &operator<<(ostream &o,const pair<T, T>&p)
{o<<"("<<p.first<<", "<<p.second<<")";return o;}

int main(void){
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; i++){
        cin >> h.at(i);
    }
    int maxv = 0;
    int c = 0;
    for(int i = 0; i < n; i++){
        if(h.at(i) >= maxv) c++;
        maxv = max(maxv, h.at(i));
    }
    cout << c << endl;
    return 0;
}
