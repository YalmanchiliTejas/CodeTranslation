#include <iostream>
#include <algorithm>


using namespace std;

int main(int argc, char** argv) {
    int n;
    cin >> n;
    int highest{0};
    int count{0};

    for (int i = 1; i < n+1; ++i) {
        int h;
        cin >> h;
        if (h >= highest) {
            ++count;
            highest = h;
        }
    }
    cout << count << endl;

    return 0;
}
