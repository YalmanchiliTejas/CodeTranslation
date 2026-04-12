#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <tuple>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <array>
#include <valarray>

using namespace std;

int main()
{
    int H, W;
    scanf("%d %d\n", &H, &W);
    vector<char> row_reached(W, false); row_reached[0] = true;
    int count = 0;
    for (int h = 0; h < H; ++h){
        vector<char> next_row_reached(W, false);
        for (int w = 0; w < W; ++w){
            const char c = getchar();
            if (c == '.') continue;
            ++count;
            if (row_reached[w] || (w > 0 && next_row_reached[w - 1])) next_row_reached[w] = true;
        }
        getchar();
        swap(row_reached, next_row_reached);
    }
    if (row_reached.back() && count == H + W - 1){
        puts("Possible");
    }else{
        puts("Impossible");
    }
}
