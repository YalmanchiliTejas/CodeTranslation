#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define all(x) (x).begin(),(x).end()

int main() {
    int h,w;
    cin >> h >> w;
    vector<string> a(h);
    vector<bool> disw(w,false);

    for (int i=0; i<h; i++) cin >> a[i];

    auto c = [](const char& c){return c == '.';};
    for (int i=h-1; i>=0; i--) {
        if (all_of(all(a[i]), c)) {
            a.erase(a.begin()+i);
        }
    }

    h = a.size();

    for (int i=0; i<w; i++) {
        bool f = true;
        for (int j=0; j<h; j++) {
            if (a[j][i] == '#') f = false;
        }
        disw[i] = f;
    }

    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            if (!disw[j])
                cout << a[i][j];
        }
        cout << endl;
    }
}