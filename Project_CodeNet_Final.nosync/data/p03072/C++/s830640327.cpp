#include <iostream>
using namespace std;

bool view_ocean(int H[], int i);

int main()
{
    int N;
    cin >> N;
    int H[N];
    for (int i = 0; i < N; i++) cin >> H[i];
    bool is_view;
    int sum_view = 0;
    for (int i = 0; i < N; i++) {
        is_view = view_ocean(H, i);
        if (is_view) sum_view++;
    }
    cout << sum_view << endl;
    return 0;
}

bool view_ocean(int H[], int i)
{
    bool is_view = true;
    for (int j = 0; j < i; j++) {
        if (H[j] <= H[i]) {}
        else {
            is_view = false;
            break;
        }
    }
    return is_view;
}
