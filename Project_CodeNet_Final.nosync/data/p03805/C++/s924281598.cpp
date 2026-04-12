#include <bits/stdc++.h>

enum State {
    NOT,
    VISITED,
};

class E {
public:
    E(int i_in) : i(i_in) {
        for (int j = 0; j < 8; ++j) {
            s[j] = NOT;
        }
    }

    E(const E& e) {
        this->i = e.i;
        for (int j = 0; j < 8; ++j) {
            this->s[j] = e.s[j];
        }
    }


    int s[8];
    int i;
};

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> v[N];
    int a, b;
    for (int i = 0; i < M; ++i) {
        std::cin >> a >> b;
        --a;
        --b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    std::queue<E> que;
    que.push(E(0));
    int cnt = 0;
    while (que.empty() == false) {
        E e = que.front(); que.pop();
        e.s[e.i] = VISITED;
        
        bool complete = true;
        for (int i = 0; i < N; ++i) {
            if (e.s[i] != VISITED) {
                complete = false;
                break;
            }
        }

        if (complete) {
            ++cnt;
            continue;
        }

        for (int d : v[e.i]) {
            if (e.s[d] == NOT) {
                E e1(e);
                e1.i = d;
                que.push(e1);
            }
        }
    }

    std::cout << cnt << std::endl;

    return 0;
}
