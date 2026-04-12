#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    using vvi = vector<vector<int>>;
    vvi val(n,vector<int>(0));

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        // 0-index
        a--;
        b--;
        val.at(a).push_back(b);
        val.at(b).push_back(a);
    }

    vector<int> num(n);
    for (int i = 0; i < n; i++) num.at(i) = i;

    int count = 0;

    do {
        vector<int>::iterator iter = num.begin();
        vector<int> tmp = val.at(*iter);

        if (*iter != 0) continue;
        if (tmp.size() == 0) continue;

        iter++;
        for (iter; iter != num.end();iter++) {
            if (find(tmp.begin(), tmp.end(), *iter) != tmp.end())
                tmp = val.at(*iter);
            else
                break;
        }
        if (iter == num.end()) {
            count++;
        }
    } while (next_permutation(num.begin(), num.end()));

    cout << count << endl;
}

