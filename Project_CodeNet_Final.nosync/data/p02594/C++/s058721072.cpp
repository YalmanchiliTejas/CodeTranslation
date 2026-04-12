#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<numeric>
#include<stack>
#include<map>
#include<queue>
#include<unordered_map>
#include<cmath>
#include<utility>

using ULL = unsigned long long;
using LL = long long;
using String = std::string;
using Ints = std::vector<int>;
using Doubles = std::vector<double>;
using Bools = std::vector<bool>;
using Strings = std::vector<std::string>;
using ULLs = std::vector<ULL>;
using LLs = std::vector<LL>;

// pythonのdictionary相当
template <typename T1, typename T2>
using Dict = std::unordered_map<T1,T2>;



int main(void) {
    int N;
    std::cin >> N;

    std::cout << (N>=30?"Yes":"No") << std::endl;

    return 0;
}