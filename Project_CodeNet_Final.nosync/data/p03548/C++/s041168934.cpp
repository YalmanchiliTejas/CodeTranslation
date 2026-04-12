#include<iostream>
#include<cstdlib>

#include<cmath>
#include<map>
#include<string>
#include<vector>
#include<algorithm> 

using namespace std;

# define p(s) std::cout << s << endl;
# define printIf(j,s1,s2) std::cout << (j ? s1 : s2) << endl;
# define YES(j) std::cout << (j ? "YES" : "NO") << endl;
# define Yes(j) std::cout << (j ? "Yes" : "No") << endl;
# define yes(j) std::cout << (j ? "yes" : "no") << endl;
# define rep(n,i) for(i = 0 ; i < n ; i++)

int main()
{
    int x,y,z;cin >> x >> y >> z;
    p((x-z)/(y+z))
}