#include <iostream>
using namespace std;
int main(int argc, char** argv) {
    int h, w; cin >> h >> w;
    char c;
    int cnt = 0;
    for (int i = 0; i < h*w; i++) { cin >> c; if (c == '#') cnt++; }
    cout << (cnt == h + w - 1 ? "Possible\n" : "Impossible\n");
}
