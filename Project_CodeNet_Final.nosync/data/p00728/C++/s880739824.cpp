#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int input_count_trial() {
    int count;
    std::cin>>count;
    return count;
}

void display(int count_trial) {
    std::vector<int> scores;
    int score;
    for(int i=0; i<count_trial; i++) {
        std::cin>>score;
        scores.push_back(score);
    }
    std::sort(scores.begin(), scores.end());
    scores.erase(scores.begin());
    scores.erase(scores.end()-1);
    int sum = std::accumulate(scores.begin(), scores.end(), 0);
    int avarage = sum/(scores.size());
    std::cout << avarage << std::endl;
    return;
}

int main() {
    int count_trial = input_count_trial();
    do {
        display(count_trial);
        count_trial = input_count_trial();
    }while(count_trial!=0);
    return 0;
}

