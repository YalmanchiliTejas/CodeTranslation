#include<iostream>
#include<vector>
#include<string>
#include<array>
#include<cmath>
#include<algorithm>

int main()
{
int h, w;
std::cin >> h >> w;
std::vector<std::string> route;

for(int i = 0; i < h + 2; i++){
    if(i == 0 || i == h + 1){
        std::string temp = "";
        for(int i = 0; i < w + 2; i++){
            temp = temp + ".";
        } 
        route.push_back(temp);
        continue;
    }
    std::string str;
    std::string base = ".";
    std::cin >> str;
    str = str + base;
    base = base + str;
    route.push_back(base);
}
int flag = 0;
for(int i = 1; i < h + 1; i++){
    for(int j = 1; j < w + 1; j++){
        if((route[i - 1][j] == '#') && (route[i][j - 1] == '#')){
            flag = 1;
            break;
        }
    }
    if(flag == 1){
        break;
    }
}
if(flag == 0){
    std::cout << "Possible" << std::endl;
} else {
    std::cout << "Impossible" << std::endl;
}

return 0;
}