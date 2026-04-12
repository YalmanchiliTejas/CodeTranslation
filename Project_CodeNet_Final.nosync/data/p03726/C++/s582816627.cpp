#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
#define END {cout << "First\n"; return 0;}

int main() {
    int N, a, b, i;
    int conLeave[100000] = {};
    vector<set<int> > g(100000);
    cin >> N;
    set<int>::iterator it;

    for (i = 0; i < N-1; i++) {
        cin >> a >> b;
        a--, b--;
        g[a].insert(b);
        g[b].insert(a);
    }

    // get a list of leaves and where they connect to
    vector<int> leaves;
    for (i = 0; i < N; i++) {
        if (g[i].size() == 1) {
            if (conLeave[*g[i].begin()]) END; 
            conLeave[*g[i].begin()]++;
            leaves.push_back(i);
            //printf("push %d\n", i+1);
        }
    }


    // Continually choose leaves
    for (i = 0; i < leaves.size(); i++) {
        int leaf = leaves[i];
        if (g[leaf].size() <= 0) END;
        int conn = *g[leaf].begin();
        //printf("leaf: %d, explore: %d\n", leaf+1, conn+1);

        // everything that was connected has one less edge
        for (it = g[conn].begin(); it != g[conn].end(); ++it) {
            //printf("check %d\n", *it+1);
            g[*it].erase(conn);
            if (g[*it].size() == 1) {
                int newConn = *g[*it].begin();
                if (conLeave[newConn]) END;
                conLeave[newConn]++;
                leaves.push_back(*it);
                //printf("push %d\n", *it+1);
            }
        }
    }

    cout << "Second\n";
}