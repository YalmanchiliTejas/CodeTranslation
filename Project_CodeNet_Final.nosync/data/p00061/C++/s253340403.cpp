#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

int main()
{
    int id, ans;
    char ch;
    int num[101] = {0};
    vector< pair<int, int> > rank;

    while (cin >> id >> ch >> ans) {
        if (!id && !ans)
            break;
        pair<int, int> p(ans, id);
        rank.push_back(p);
    }
    sort(rank.begin(), rank.end(), greater< pair<int, int> >());

    int bf, r;
    r = 1; 

    num[rank[0].second] = r;
    for (int i = 1; i < rank.size(); i ++) {
        if (rank[i - 1].first != rank[i].first) 
            r++;
        num[rank[i].second] = r;
    }

    while (cin >> id) {
        cout << num[id] << endl;
    }

    return 0;
}