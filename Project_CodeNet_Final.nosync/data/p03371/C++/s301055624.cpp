#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
template<class T> istream& operator >> (istream& s, vector<T>& v)
{ for (T& x: v) { s >> x; } return s;}
void yes(){ cout << "Yes" << endl; }
void no(){ cout << "No" << endl; }
int SIZE(string s){ return (int)s.size(); }

int main(){
    cout << setprecision(16);
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    int num = min(x,y); x-= num; y -= num;
    int ans = min(num*a+num*b, c*num*2);
    if(x > 0) ans += min(x*a, x*c*2);
    else if(y > 0) ans += min(y*b, y*c*2);
    cout << ans << endl;
    return 0;
}
