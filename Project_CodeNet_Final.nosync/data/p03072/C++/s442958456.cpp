
#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int h = 0;
    int count = 0;
    for (int i = 0; i < N; i++) {
        int H;
        cin >> H;

        if (H >= h) {
            h = H;
            count++;
        }
    }

    cout << count << endl;
    
    return 0;
}
