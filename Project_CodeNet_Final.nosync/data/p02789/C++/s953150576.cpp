// no proof is included. may have unused libraries. may have unused variables. possibly dirty code - contest mode

#include <iostream> // std::cin, std::cout
#include <cstring> // std::memset()
#include <algorithm> // std::max_element(), std::min_element(), std::reverse(), std::sort(), std::__gcd()

using namespace std;

bool debug = true;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    cout << (n == m ? "Yes" : "No") << endl;

    return 0;
}
