#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 8
#define MAX_M 28

bool is_path(int N, int M, int *a, int *b, int *order) {
    bool is_path = true;
    for (int i = 1; i < N; i++) {
        bool exist_path = false;
        for (int j = 0; j < M; j++) {
            if (a[j] == order[i-1] && b[j] == order[i]) {
                exist_path = true;
            }
            if (a[j] == order[i] && b[j] == order[i-1]) {
                exist_path = true;
            }
        }
        if (!exist_path) {
            is_path = false;
        }
    }
    return is_path;
}

int main() {
    int N, M, a[MAX_M], b[MAX_M];
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> a[i] >> b[i];
    }
    int order[MAX_N];
    for (int i = 0; i < N; i++) {
        order[i] = i+1;
    }
    int num_of_path = 0;
    do {
        if (is_path(N, M, a, b, order)) {
            num_of_path++;
        }
    } while (next_permutation(order+1, order+N));
    cout << num_of_path << endl;
    return 0;
}