#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H_list;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        H_list.emplace_back(tmp);
    }
    int num_buildings_with_good_sceneary = 0;
    int cur_highest = -1;
    for (int i = 0; i < N; i++) {
        int height = H_list.at(i);
        if (height >= cur_highest) {
            num_buildings_with_good_sceneary += 1;
        }
        cur_highest = max(cur_highest, height);
    }
    cout << num_buildings_with_good_sceneary << "\n";
}