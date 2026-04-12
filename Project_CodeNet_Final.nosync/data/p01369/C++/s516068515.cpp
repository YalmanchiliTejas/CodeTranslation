#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

void make_hand(std::vector<int> &hand) {
    for (int i = 7; i <= 15; i++) {
        hand[i] = 1;
    }
    hand[20] = 1;
    hand[24] = 1;
}

int main(void) {
    std::string s;
    const char* c;
    int now_hand;
    int search_space;
    int change_count;
    std::vector<int> hand(26, 0);
    make_hand(hand);
    std::cin >> s;
    while(s != "#") {
        c = s.c_str();
        change_count = 0;

        search_space = (int) c[0] - 97;;
        now_hand = hand[search_space];

        for (int i = 1; i < s.size(); i++) {
            search_space = (int) c[i] - 97;;
            if (hand[search_space] != now_hand) {
                change_count++;
                now_hand = hand[search_space];
            }
        }
        std::cout << change_count << std::endl;
        
        std::cin >> s;
    }

    return EXIT_SUCCESS;
}