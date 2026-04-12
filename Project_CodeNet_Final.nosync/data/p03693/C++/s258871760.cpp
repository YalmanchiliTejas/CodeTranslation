#include <bits/stdc++.h>

using namespace std;

#define fst(t) std::get<0>(t)
#define snd(t) std::get<1>(t)
#define thd(t) std::get<2>(t)
#define unless(p) if(!(p))
#define until(p) while(!(p))

using ll = long long;
using P = std::tuple<int,int>;

const int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1}, dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

int main(){
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int R, G, B;
    std::cin >> R >> G >> B;

    const string YESNO[2] = {"NO", "YES"};
    std::cout << YESNO[(G * 10 + B) % 4 == 0] << std::endl;
}
