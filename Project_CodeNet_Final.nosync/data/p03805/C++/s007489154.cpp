#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>

int main(){
    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<int, int>> pairs;
    for(int i = 0; i < m; ++i){
        int a, b;
        std::cin >> a >> b;
        pairs.push_back(std::make_pair(a, b));
        pairs.push_back(std::make_pair(b, a));
    }

    std::vector<int> preNodes;
    for(int i = 2; i <= n; ++i){
        preNodes.push_back(i);
    }

    int count = 0;
    do{
        std::vector<int> nodes{1};
        nodes.insert(nodes.end(), preNodes.begin(), preNodes.end());        

        bool flg = true;
        int i = 1;
        while(flg && i < n){
            auto interest = std::make_pair(nodes.at(i - 1), nodes.at(i++));
            flg = pairs.end() != std::find(pairs.begin(), pairs.end(), interest);
        }
        
        if(flg){
            ++count;
        }
    }while(std::next_permutation(preNodes.begin(), preNodes.end()));

    std::cout << count << std::endl;

    return 0;
}