#include<iostream>
#include<vector>



int main()
{
    int N;
    std::cin >> N;
    std::vector<int> H;

    for(int i =0; i<N; ++i){
        int a;
        std::cin >>a;
        H.push_back(a);
    }
    int max_height = H[0];
    int count = 0;
    for(int i = 0; i<N; ++i){
        if(max_height <= H[i]){
            max_height = H[i];
            count++;
        }
    }
    std::cout << count << std::endl;
    return 0;
}
