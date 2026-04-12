#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    int N; cin >> N;
    
    int highest_hotel = 0, hotel = 0;
    for (int i = 0; i < N; i++) {
        int H; cin >> H;
        if (highest_hotel <= H) {
            highest_hotel = H;
            hotel++;
        }
    }

    cout << hotel << endl;
    return 0;
}
