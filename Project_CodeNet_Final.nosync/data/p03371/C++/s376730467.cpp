#include<iostream>
#include<map>
#include<vector>
#include<cmath>
#include<string>
#include <algorithm> 
using namespace std;

# define p(s) std::cout << s << endl;
# define printIf(j,s1,s2) cout << (j ? s1 : s2) << endl;
# define YES(j) cout << (j ? "YES" : "NO") << endl;
# define Yes(j) std::cout << (j ? "Yes" : "No") << endl;



int main()
{
    long long int a,b,c,x,y;cin >> a >> b >> c >> x >> y;

    // バラ買戦略
    long long int mi = a*x + b*y;

    // ハーフで余りなく
    long long z = min(x,y);
    long long int mi2 = c*z*2+a*(x-z)+b*(y-z);

    // ハーフでぎゃんぜめ
    z = max(x,y);
    long long int mi3 = c*z*2;

    mi = min(mi,mi2);
    mi = min(mi,mi3);
    p(mi)
} 