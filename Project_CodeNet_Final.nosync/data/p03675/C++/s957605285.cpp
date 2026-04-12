#include <iostream>
#include <list>
#include <algorithm>

int n;
std::list<int> b;
bool isOdd;

int main(int argc, char *argv[])
{
    std::cin >> n;
    isOdd = n % 2;
    int tmp;
    for(int i = 0; i < n; i++){
        std::cin >> tmp;
        if(isOdd){
            b.push_front(tmp);
        }
        else{
            b.push_back(tmp);
        }
        isOdd = !isOdd;
    }
    for(auto itr = b.begin(); itr != b.end(); itr++){
        std::cout << ' ' << *itr;
    }
    return 0;
}
