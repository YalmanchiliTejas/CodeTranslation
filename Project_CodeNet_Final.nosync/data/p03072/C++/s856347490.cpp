#include<iostream>
#include<algorithm>
#include<vector>

int main () {
    int n;
    std::cin >> n;

    std::vector<int> h(n);
    for (int i = 0; i < n; i++) {
        std::cin >> h[i];
    }

    int ans = 1;

    for (int i = 1; i < n; i++) {
        bool flag = true;
        for (int j = 0; j < i; j++)
        {
            if(h[j] > h[i]) {
                flag = false;
            }
        }

        if(flag) {
            ans++;
        }

    }

    std::cout << ans << std::endl;
}