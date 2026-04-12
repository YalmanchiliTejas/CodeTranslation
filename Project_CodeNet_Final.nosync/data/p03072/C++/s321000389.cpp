#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <sstream>

using namespace std;


int main(int argc, const char * argv[]) {
    int N; cin >> N;
    int prev_max = 0;
    int count = 0;
    for (int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        if (prev_max <= tmp) {
            count++;
        }
        prev_max = max(prev_max, tmp);
    }
    cout << count << endl;
    
    return 0;
}