#include <iostream>
#include <map>

int n, m;

int search(std::map<int, std::map<int, bool> > *nodes, std::map<int, bool> *a, int k) {
    int count = 0;
    int i = 0;
    for (std::map<int, bool>::iterator j = (*a).begin(); j != (*a).end(); ++j) {
        if (j->second) {
            i++;
        } else {
            break;
        }
    }
    if (i == n) {
        return 1;
    }
    for (std::map<int, bool>::iterator j = (*nodes)[k].begin(); j != (*nodes)[k].end(); ++j) {
        if (!j->second && !(*a)[j->first]) {
            std::map<int, std::map<int, bool> > b = *nodes;
            std::map<int, bool> c = *a;
            b[k][j->first] = true;
            b[j->first][k] = true;
            c[j->first] = !c[j->first];
            count += search(&b, &c, j->first);
        }
    }
    return count;
}

int main() {
    std::cin >> n >> m;
    std::map<int, std::map<int, bool> > nodes;
    std::map<int, bool> a;
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        nodes[a][b] = false;
        nodes[b][a] = false;
    }
    a[1] = true;
    int c = search(&nodes, &a, 1);
    std::cout << c << std::endl;
}