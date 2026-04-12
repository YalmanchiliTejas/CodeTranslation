#include <bits/stdc++.h>
using namespace std;

#define ALL(a) begin(a),end(a)
#define COUNTOF(a) (sizeof(a)/sizeof(a[0]))
#define SP << " " <<
#define FMT(a) #a<<":"<<a 
#define FMT2(a,b) #a<<":"<<a<<", "<<#b<<":"<<b 
#define FMT3(a,b,c) #a<<":"<<a<<", "<<#b<<":"<<b<<", "<<#c<<":"<<c 
#define FMT4(a,b,c,d) #a<<":"<<a<<", "<<#b<<":"<<b<<", "<<#c<<":"<<c<<", "<<#d<<":"<<d 
typedef long long ll;
template<class T> istream& operator >> (istream& s, vector<T>& v) {
  for (T& x: v) s >> x;
  return s;
}
inline void Yes(bool f=true){cout<<(f?"Yes":"No")<<endl;}
inline void YES(bool f=true){cout<<(f?"YES":"NO")<<endl;}
#define ANS(a) cout<<a<<endl

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);
    //cout<<std::fixed<<std::setprecision(10);
    const vector<char> v={'a','e','i','o','u'};
    char c;
    cin >> c;
    cout << (find(ALL(v),c)!=v.end()?"vowel":"consonant") << endl;
}
