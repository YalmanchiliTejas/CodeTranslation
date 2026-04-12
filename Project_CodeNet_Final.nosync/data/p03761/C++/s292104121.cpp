#include<iostream>
#include<vector>
#include<string>

const int ALPHABET = 'z' - 'a' + 1;

int main(){
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> alphabet(n, std::vector<int>(ALPHABET, 0));
    for(int i = 0; i < n; i++){
        std::string S;
        std::cin >> S;
        for(int j = 0; j < S.size(); j++){
            alphabet[i][S[j] - 'a']++;
        }
    }

    // 共通しているものを探す
    std::string out;
    for(int j = 0; j < ALPHABET; j++){
        int minCnt = 50 * 50;
        for(int i = 0; i < n; i++){
            minCnt = std::min(minCnt, alphabet[i][j]);
            if(minCnt == 0) break;
        }

        if(minCnt != 0){
            out += std::string(minCnt, 'a' + j);
        }
    }

    if(out.size() > 0){
        std::cout << out << std::endl;
    }else{
        std::cout << std::endl;
    }
    
    return 0;
}
