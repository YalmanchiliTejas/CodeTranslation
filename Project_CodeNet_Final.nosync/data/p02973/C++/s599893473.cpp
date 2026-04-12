#include<iostream>
#include<vector>
#include<algorithm>

int main(void){
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::vector<int> max_vec;
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
    }
    max_vec.push_back(-a[0]);
    for(int i = 1; i < n; i++){
        int cur = -a[i];
        auto pos = std::upper_bound(max_vec.begin(), max_vec.end(), cur);
        if(pos != max_vec.end()){
            *pos = cur;
        }else{
            max_vec.push_back(cur);
        }
    }
    std::cout << max_vec.size() << std::endl;
    return 0;
}
