#include <bits/stdc++.h>

using namespace std;

#define fst(t) std::get<0>(t)
#define snd(t) std::get<1>(t)
#define thd(t) std::get<2>(t)

using ll = long long;
using P = std::tuple<int,int>;

const int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1}, dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

std::deque<int> deq;

int main(){
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int N;
    std::cin >> N;

    for(int i=0;i<N;++i){
        int a;
        std::cin >> a;
        
        if(i % 2 == 0){
            deq.push_front(a);
        }else{
            deq.push_back(a);
        }
    }

    for(int i=0;i<N;++i){
        int x;
        
        if((N - 1) % 2 == 0){
            x = deq.front();
            deq.pop_front();
        }else{
            x = deq.back();
            deq.pop_back();
        }

        std::cout << x << " \n"[i+1==N];
    }
}
