#include<iostream>

int main(int argc, char const *argv[]) {

    int chair_space;
    int space_between_man;
    int man_space;

    std::cin >> chair_space >> man_space >> space_between_man;

    /** 初めのスペースは確定 **/
    chair_space -= space_between_man;

    /** 1人分の幅を算出 **/
    man_space = man_space + space_between_man;

    /** 残りスペースから座れる人数を算出 **/
    int answer = chair_space / man_space;
    std::cout << answer << '\n';

    return 0;
}
