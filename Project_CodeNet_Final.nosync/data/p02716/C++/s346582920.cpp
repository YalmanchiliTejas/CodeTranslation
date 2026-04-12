#include <bits/stdc++.h>

using namespace std;
using LL = long long;

constexpr LL INF = 1e15;

struct ListNode {
    ListNode() = default;
    ListNode(LL _data, LL _id) : data(_data), id(_id) {}
    bool operator<(const ListNode& other) const {
        return data == other.data ? id < other.id : data < other.data;
    }
    LL data = -INF, id = -1;
    list<ListNode>::iterator itr;
};

LL n, cnt, ans;
map<LL, bool> deleted;
list<ListNode> lst;
priority_queue<ListNode> q;

inline void calc(int tot = 0) {
    while (!q.empty() && tot < n / 2) {
        auto cur= q.top();
        q.pop();
        if (deleted[cur.id]) continue;
        ans += cur.data, tot++;

        LL data(0);
        auto itr = cur.itr;
        itr--;
        data += itr->data, deleted[itr->id] = true, itr = lst.erase(itr);
        data -= itr->data, deleted[itr->id] = true, itr = lst.erase(itr);
        data += itr->data, deleted[itr->id] = true, itr = lst.erase(itr);

        auto newNode = ListNode(data, cnt++);
        newNode.itr = lst.insert(itr, newNode);
        q.push(newNode);
    }
}

int main() {
    scanf("%d", &n);
    lst.emplace_back(ListNode(-INF, cnt++));
    for (int i = 0, tmp; i < n; i++) {
        scanf("%d", &tmp);
        auto newNode = ListNode(tmp, cnt++);
        newNode.itr = lst.insert(lst.end(), newNode);
        q.push(newNode);
    }
    lst.emplace_back(ListNode(-INF, cnt++));
    calc();
    printf("%lld\n", ans);
    return 0;
}