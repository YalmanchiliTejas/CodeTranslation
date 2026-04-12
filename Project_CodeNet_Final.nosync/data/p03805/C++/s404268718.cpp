#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, M;
    int a[8*(8-1)/2];
    int b[8*(8-1)/2];
    int i, j;

    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        cin >> a[i] >> b[i];
    }

    // 1起点を調べるため、2～N
    vector<int> order(N-1);
    for(i = 0; i < (N-1); i++) {
        order[i] = i + 2;
    }

    int count = 0;
    do {
        int current = 1;
        for(i = 0; i < (N-1); i++) {
            for(j = 0; j < M; j++) {
                if((a[j] == current && b[j] == order[i]) ||
                   (a[j] == order[i] && b[j] == current)) {
                    current = order[i];
                    break;
                }
            }
            if(j == M) {
                break;
            }
        }
        if(i == (N-1)) {
            count += 1;
        }
    } while(next_permutation(order.begin(), order.end()));
    cout << count << endl;

    return 0;
}