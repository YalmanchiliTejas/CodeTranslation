#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <functional>

int main()
{
    long N;
    std::cin >> N;
    std::vector<std::vector<int> > map(50,std::vector<int>(26));
    for(long i=0; i<N; i++){
        std::string H;
        std::cin >> H;
        int length=H.length();
        for(int j=0; j<length; j++){
            map[i][H[j]-97]+=1;
        }
    }


    for(int i=0; i<26; i++){
        std::vector<int> temp;
        for(int j=0; j<N; j++){
            temp.push_back(map[j][i]);
        }
        std::sort(temp.begin(),temp.end());
        int num=temp[0];
        for(int j=0; j<num;j++){
            std::string S;
            S=i+97;
            std::cout << S;
            temp.clear();
        }
    }
    std::cout << std::endl;
    return 0;
}