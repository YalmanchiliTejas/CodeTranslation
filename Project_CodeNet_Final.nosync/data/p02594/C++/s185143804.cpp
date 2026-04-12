#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

int main() {
    std :: ios_base :: sync_with_stdio(false);

    int t = 1;
    //std :: cin >> t;

    while(t--) {
        int n;
        std :: cin >> n;

        std :: cout << (n >= 30 ? "Yes\n" : "No\n");
    }
}