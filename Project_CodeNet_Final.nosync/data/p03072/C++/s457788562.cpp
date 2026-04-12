#include <iostream>
//#include <string>
#include <vector>
//#include <algorithm>
using namespace std;

int main() {
        int N;
        cin >> N;
        vector<int> H(N);
        for(int i = 0; i < N; i++) {
                cin >> H[i];
        }

        int hmax = 0;
        int cnt = 0;
        for(auto itr = H.begin(); itr != H.end(); itr++) {
                if(hmax <= *itr) {
                        hmax = *itr;
                        cnt++;
                }
        }

        cout << cnt << endl;
}
