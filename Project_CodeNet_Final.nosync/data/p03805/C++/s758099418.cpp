#include <iostream>
#include <vector>

int trace(int pt, int record, int all_mask, std::vector<std::vector<int>>& connectTo, int num){
    if((record & all_mask) == all_mask){
        return num+1;
    }
    int sum = num;
    std::vector<int> connections = connectTo.at(pt);
    for(unsigned int i = 0; i < connections.size(); i++){
        int np = connections.at(i);
        int mask = 1 << np;
        if((record & mask) == 0){
            sum = trace(np, (record | mask), all_mask, connectTo, sum);
        }
    }
    return sum;
}


int main(int argc, char **argv)
{
    int N, M;
    std::cin >> N >> M;
    std::vector<int> a(M), b(M);
    for(int i = 0; i < M; i++){
        std::cin >> a.at(i) >> b.at(i);
    }
    std::vector<std::vector<int>> connectTo(N, std::vector<int>(0));
    for(int i = 0; i < M; i++){
        connectTo.at(a.at(i)-1).push_back(b.at(i)-1);
        connectTo.at(b.at(i)-1).push_back(a.at(i)-1);
    }
    int all_mask = (1 << N) - 1;
    int num = trace(0, 0x001, all_mask, connectTo, 0);
    std::cout << num << std::endl;
}
