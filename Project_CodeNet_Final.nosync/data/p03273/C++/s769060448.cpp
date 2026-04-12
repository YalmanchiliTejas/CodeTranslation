#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

void main_()
{
    ll H, W;
    vector<string> ass;
    cin >> H >> W;
    copy_n(istream_iterator<string>(cin), H, back_inserter(ass));

    // 横列が全て空の行を消去
    ass.erase(
        remove_if(begin(ass), end(ass),
            [](auto&& as) {
                return as.find_first_not_of('.') == string::npos;
            }),
        end(ass));

    // 縦列がすべて空のマスに削除マーク'x'をつける
    for (int i = 0; i < W; ++i) {
        if (all_of(begin(ass), end(ass), [i](auto&& as) { return as[i] == '.'; })) {
            for (auto&& as : ass) {
                as[i] = 'x';
            }
        }
    }

    // 削除マークがついたマスを削除
    for (auto&& as : ass) {
        as.erase(
            remove_if(begin(as), end(as),
                [](auto a) {
                    return a == 'x';
                }),
            end(as));
    }

    for (auto&& as : ass) {
        cout << as << "\n";
    }
}
int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    main_();
    return 0;
}
