#include <iostream>
#include <queue>
#include <vector>
#include <utility>

auto dfs(int current, const std::vector<std::vector<int>>& links, std::vector<bool> &passed) -> int
{
    //std::cout << current << std::endl;
    if(passed[current])
    {
        //std::cout << "already: : " << current << std::endl;
        return 0;
    }

    passed[current] = true;
    for(auto p: passed)
    {
        if(!p)
        {
            goto cont;
        }
    }
    //std::cout << "goal: : " << current << std::endl;
    return 1;

cont:

    auto reached_num = 0;
    for(auto next: links[current])
    {
        auto n_passed = std::vector<bool>(passed.size());
        std::copy(passed.begin(), passed.end(), n_passed.begin());
        reached_num += dfs(next, links, n_passed);
    }

    //std::cout << "finish: "  << current << std::endl;
    return reached_num;
}

int main(int argc, char const* argv[])
{
    int n, m;
    std::cin >> n >> m;

    auto links = std::vector<std::vector<int>>(n, std::vector<int>());
    for(int i=0; i<m;++i)
    {
        int n1, n2;
        std::cin >> n1 >> n2;

        links[n1 - 1].push_back(n2 - 1);
        links[n2 - 1].push_back(n1 - 1);
    }

    auto passed = std::vector<bool>(n, false);
    std::cout << dfs(0, links, passed) << std::endl;
}