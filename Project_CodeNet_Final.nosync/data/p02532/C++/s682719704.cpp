#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
using namespace std;

int main(void) {
    int num; cin >> num;
    stack<char> mountain[101];
    vector<char> output;
    
    string operation;
    while(cin >> operation, operation != "quit") {
        int which; cin >> which;
        
        if(operation == "push") {
            char color; cin >> color;
            mountain[which].push(color);
        } else if(operation == "pop") {
            output.push_back(mountain[which].top());
            mountain[which].pop();
        } else if(operation == "move") {
            int to; cin >> to;
            mountain[to].push(mountain[which].top());
            mountain[which].pop();
        }
    }
    vector<char>::iterator ite;
    for(ite = output.begin(); ite != output.end(); ite++) {
        cout << *ite << endl;
    }
    return(0);
}