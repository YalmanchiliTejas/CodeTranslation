#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {                                                                                                int N;                                                                                                  cin >> N;
    vector<int> vec(N);
    for (int i = 0; i< N;i++) {                                                                                 cin >> vec[i];                                                                                      }
    int max_point = 0;
    int count = 0;                                                                                          for (auto &x: vec) {                                                                                        if (max_point <= x) {
            max_point = x;
            count += 1;
        }
    }
    cout << count;
}
