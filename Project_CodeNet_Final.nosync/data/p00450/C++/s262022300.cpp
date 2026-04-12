#include <cstdio>
#include <vector>

using namespace std;

#define WHITE 0
#define BLACK 1

typedef struct _range {
    _range (int l, int r, int color) {
        left = l;
        right = r;
        range_color = color;
    }

    int left;
    int right;
    int range_color;
} Range;

int main() {
    while (1) {
        int i;
        int n;
        vector<Range> stones;
        stones.clear();
        int white_num = 0;

        scanf("%d", &n);
        if (!n) return 0;

        stones.push_back(Range(0, 0, WHITE));
        for (i=1;i<=n;i++) {
            int color;
            scanf("%d", &color);

            if (i%2) {
                if (stones.back().range_color == color) {
                    stones.rbegin()->right += 1;
                } else {
                    int new_left = stones.back().right;
                    stones.push_back(Range(new_left, new_left+1, color));
                }
            } else {
                vector<Range>::reverse_iterator last = stones.rbegin();
                last->range_color = color;
                last->right += 1;
            }

            if (stones.size() > 1) {
                vector<Range>::reverse_iterator it1 = stones.rbegin();
                vector<Range>::reverse_iterator it2 = stones.rbegin();
                it2++;
                if (it1->range_color == it2->range_color) {
                    it2->right = it1->right;
                    stones.pop_back();
                }
            }
        }

        vector<Range>::iterator it = stones.begin();
        while (it != stones.end()) {
            if (it->range_color == WHITE) white_num += it->right - it->left;
            it++;
        }

        printf("%d\n", white_num);
    }
}