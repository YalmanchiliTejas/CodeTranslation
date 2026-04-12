#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    int highest = 0;
    int result = 1;

    cin >> N;

    vector<int> h(N);
    
    int tmp = 0;
    int i = 0;
    while(cin >> tmp) {
        h[i] = tmp;
        i ++;
        if(i >= N) {
            break;
        }
    }

    highest = h[0];

    for(int i = 1; i < h.size(); i++) {
        if(highest <= h[i]) {
            result ++;
            highest = h[i];
        }
    }

    cout << result << endl;
}