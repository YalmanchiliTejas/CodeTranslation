#include <iostream>
#include <string>
#include <stack>
#include <vector>


using std::cout;
using std::cin;
using std::endl;

int main()
{
    int towers_num;
    cin >> towers_num;

    std::vector<std::stack<char>> stacked(towers_num);

    std::string op;
    while (true) {
        cin >> op;
        if (op == "quit") {
            break;
        } else if (op == "push") {
            int tower;
            char color;
            cin >> tower >> color;
            stacked.at(tower - 1).push(color);
        } else if (op == "pop") {
            int tower;
            cin >> tower;
            cout << stacked.at(tower - 1).top() << endl;
            stacked.at(tower - 1).pop();
        } else if (op == "move") {
            int from, to;
            cin >> from >> to;
            stacked.at(to - 1).push(stacked.at(from - 1).top());
            stacked.at(from - 1).pop();
        } else {
            cout << "ERROR!" << endl;
            break;
        }
    }

    return 0;
}