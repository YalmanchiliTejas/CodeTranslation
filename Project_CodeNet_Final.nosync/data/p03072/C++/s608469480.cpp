#include <stdio.h>
#include <iostream>
#include <string>
#include <vector> 
#include <algorithm>
#include <typeinfo>
#include <cmath>
#include <numeric>
using namespace std;


int main()
{
    int N;
    std::cin >> N;
    std::vector<int> Height(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin >> Height[i];
    }
    
    std::vector<int> prev_max_Height(N);
    int num = 1;
    prev_max_Height[0] = Height[0];
    
    for (int i = 1; i < N; ++i)
    {
        if(Height[i] >= prev_max_Height[i-1]){
            ++num;
            prev_max_Height[i] = Height[i];
        }else{
            prev_max_Height[i] = prev_max_Height[i-1];
        }
    }
    std::cout << num << "\n";
}