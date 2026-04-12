#include <iostream>
#include <vector>
#include <set>

int main() {
    int N;
    std::cin >> N;
    std::cin.ignore();
    int n = N;
    std::vector<int> A;
    A.reserve(N);
    while(n-->0){
        int v;
        std::cin >> v;
        A.push_back(v);
        std::cin.ignore();
    }
    std::vector<int> vals;
    vals.reserve(N);
    vals.push_back(*A.rbegin());
    for(auto it = A.rbegin() + 1; it!=A.rend();++it) {
        auto upper = std::upper_bound(vals.begin(),vals.end(),*it);
        if(upper == vals.end()) {
            vals.push_back(*it);
        } else {
            *upper = (*it);
        }
    }
    
    std::cout << vals.size() << std::flush;  
}