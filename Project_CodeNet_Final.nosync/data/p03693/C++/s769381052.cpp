#include<bits/stdc++.h>


void input(); template<typename First,typename... Rest> void input(First&,Rest&...);
void inputVector(); template<typename First,typename... Rest>  void inputVector(std::vector<First>&,Rest&...);
#define loop(n) for(int i = 0;i < (int)(n);++i)


void calculate(){
    std::string r,g,b;
    input(r,g,b);
    if(stoi(g + b) % 4 == 0) std::cout << "YES\n";
    else std::cout << "NO\n";
}

int main(int,char**){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    calculate();
}



void input(){return;}
template<typename First,typename... Rest>
void input(First &first,Rest&... rest){
    std::cin >> first;
    input(rest...);
}

void inputVector(){return;}
template<typename First,typename... Rest> 
void inputVector(std::vector<First> &first,Rest&... rest){
    int N = first.size();
    for(int i = 0;i < N;i++){
        std::cin >> first[i];
    }
    inputVector(rest...);
}