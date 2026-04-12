#include <iostream>
#include <vector>

void print(std::vector<int> readVec){
    int sz = readVec.size();
    for(int i = 0; i < sz; ++i){
        std::cout << readVec.at(i);
        if(sz - 1 != i){
            std::cout << " ";
        }else{
            std::cout << std::endl;
        }
    }
}

int main(){
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> matrix(26, std::vector<int>(n, 0));
    for(int i = 0; i < n; ++i){
        std::string s;
        std::cin >> s;
        int sz = s.size();
        for(int j = 0; j < sz; ++j){
            ++matrix.at(s.at(j) - 97).at(i);
        }
    }

//    print(matrix.at(0));

    std::string ans = "";
    for(int i = 0; i < 26; ++i){
        int val = *std::min_element(matrix.at(i).begin(), matrix.at(i).end());
        for(int j = 0; j < val; ++j){
            ans += (char)(i + 97);
        }
    }

    std::cout << ans << std::endl;    

    return 0;
}