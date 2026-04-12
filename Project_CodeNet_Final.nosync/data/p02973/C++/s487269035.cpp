#include <iostream>
#include <vector>
using namespace std;

int search_best_color(vector<int> &colors, int a) {
    int l = 0;
    int r = colors.size() - 1;
    while ((r-l) > 1) {
        int c = (l + r) / 2;
        if (colors[c] < a) {
            r = c;
        } else {
            l = c;
        }
    }
    if (colors[l] < a) {
        return l;
    } else if (colors[r] < a) {
        return r;
    } else {
        return -1; /* abort */
    }
}

int main() {
    int N;
    cin >> N;
    int color_n = 0;
    vector<int> colors;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        if (color_n == 0) {
            colors.push_back(a);
            color_n++;
        } else if (colors[color_n-1] >= a) {
            colors.push_back(a);
            color_n++;
        } else {
            int j = search_best_color(colors, a);
            colors[j] = a;
        }
    }
    cout << color_n << "\n";
    return 0;
}
