#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n_block;
    cin >> n_block;
    stack<char> *blocks = new stack<char>[n_block];
    string str;
    char color;
    for (;;) {
	cin >> str;
	if (str == "quit") {
	    break;
	} else if (str == "push") {
	    cin >> n_block >> color;
	    blocks[n_block - 1].push(color);
	} else if (str == "pop") {
	    cin >> n_block;
	    cout << blocks[n_block - 1].top() << endl;
	    blocks[n_block - 1].pop();
	} else if (str == "move") {
	    int dept, dest;
	    cin >> dept >> dest;
	    blocks[dest - 1].push(blocks[dept - 1].top());
	    blocks[dept - 1].pop();
	}
    }
    delete[] blocks;
    return 0;
}