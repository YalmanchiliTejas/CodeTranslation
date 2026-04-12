#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    int N; cin >> N;

    int hotel = 0, highest = -1;
    for (int i = 0; i < N; i++) {
        int h;
        cin >> h;
        if (h >= highest) {
            hotel++;
            highest = h;
        }
    }

    cout << hotel << endl;
    return 0;
}