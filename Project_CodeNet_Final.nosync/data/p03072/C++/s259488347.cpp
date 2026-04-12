#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int main(void){
    int N;
    vector<int> H;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int v;
        scanf("%d", &v);
        H.insert(H.begin() + i, v);
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        int a = H[i];
        bool is = false;
        for (int j = 0; j < i; j++) {
            int b = H[j];
            if (b > a) {
                is = true;
                break;
            }
        }
        if (!is) {
            count++;
        }
    }

    printf("%d\n", count);
    fflush(stdout);

    return 0;
}