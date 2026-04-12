#include <iostream>
#include <assert.h>
#include <vector>
#include <algorithm>
//#include <functional>
#include <set>
//#include <cmath>
//#include <queue>

int main(){
    int32_t N;
    std::cin >> N;

    std::vector<int32_t> A(N);
    for(auto& i : A){
        std::cin >> i;
    }

    // naiive: detect ascending sequence for each Ai?
    // Greedy: start from An and search max j where Aj < An. repeat to A0
    //  - delete from the queue? -> high deletion cost and O(N^2)
    //  -> not feasible where N = 10^5
    // building buckets with the minimux val so far
    //  if next item > every min -> new bucket
    //  if next item < mina && next item < minb -> attach to mina (where  mina < minb)
    //  to avoid bucket check every time, hold max val and min pointer 
    //std::priority_queue<int32_t, std::vector<int32_t>, std::greater<int32_t>> colour_que;
    //std::vector<int32_t> colour_que;
    std::multiset<int32_t> colour_que;
    for(int32_t i = A.size() -1; i >= 0; i--){
        auto it = colour_que.upper_bound(A[i]);
        if(it != colour_que.end()){
            //std::cout << "colour update from: " << *it << " to " << A[i] << std::endl;
            colour_que.erase(it);
        }
        colour_que.insert(A[i]);
        //for(auto& q : colour_que){
        //    std::cout << "i:pqs " << i << ":" << q << std::endl;
        //}
    }
    std::cout << colour_que.size();

    return 0;
}
