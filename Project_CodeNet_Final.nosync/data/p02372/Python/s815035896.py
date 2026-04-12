import sys
from heapq import heappop, heappush
from typing import List


def func(start: int) -> List[int]:
    global edges
    cost = [sys.maxsize] * n
    que = [(0, start)]
    cost[start] = 0

    while que:
        acc, num = heappop(que)
        for weight, to in edges[num]:
            if weight + acc < cost[to]:
                cost[to] = weight + acc
                heappush(que, (weight + acc, to))
    return cost


if __name__ == "__main__":
    n = int(input())
    edges = [[] for _ in range(n)]  # type: ignore
    for _ in range(n - 1):
        s, t, w = map(int, input().split())
        edges[s].append((w, t))
        edges[t].append((w, s))

    cost1 = func(0)
    max_ind = cost1.index(max(cost1))
    cost2 = func(max_ind)
    max_ind2 = cost2.index(max(cost2))
    cost3 = func(max_ind2)
    for i in range(n):
        print(max(cost2[i], cost3[i]))

