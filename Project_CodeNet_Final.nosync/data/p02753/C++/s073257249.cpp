#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#define DEBUG(x) std::cout << '>' << #x << ':' << x << '\n';
#define PRINTVEC(x) for (int i = 0; i < (int)x.size(); i++) std::cout << x[i] << ' '; std::cout << '\n';
#define PRINTP(x) for (int i = 0; i < (int)x.size(); i++) std::cout << x[i].first << ' ' << x[i].second << '\n'; std::cout << '\n';
#define io std::ios_base::sync_with_stdio(false);std::cin.tie(NULL);   
const int INF = 1<<29;
typedef long long ll;



int main()
{
	io;
    #ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout);  
    #endif

    std::string s;
    std::cin >> s;
    int a = 0, b = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == 'A') a++;
        else b++;
    std::cout << (a == 0 || b == 0 ? "No" : "Yes");

    #ifndef ONLINE_JUDGE   
    //std::cout << '\n' << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    #endif
    return 0;
}
