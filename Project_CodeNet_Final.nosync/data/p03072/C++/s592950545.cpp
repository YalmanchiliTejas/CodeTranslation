#include <iostream>
#include <vector>
using namespace std;

int main() { 
    int N; cin >> N;
    vector<int> H;
    for(int i=0; i<N; i++) {
        int h; cin >> h;
        H.push_back(h);
    }

    int ct = 1;
    int minH = H[0];
    for (int i=1; i<N; i++) {
        if (H[i] >= minH) {
            ct++;
            minH = H[i];
        }
    }

    cout << ct << endl;

    
    return 0;
}