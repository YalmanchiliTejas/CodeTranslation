#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
template<class T> istream& operator >> (istream& s, vector<T>& v)
{ for (T& x: v) { s >> x; } return s;}
void yes(){ cout << "YES" << endl; }
void no(){ cout << "NO" << endl; }

int main(){
    int x; cin >>x;
    if(x == 3 || x == 5 || x == 7) yes();
    else no();
    return 0;
}